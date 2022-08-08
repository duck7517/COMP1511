/*******************************************************************************
> CSpotify - 20T3 COMP1511 Assignment 2
| cspotify.c
|
| zID: z5312476
| Name: Lisa Guo
| Date: November 2020
| Program Description:
| This program mimics a music streaming platform and allows the user to add
| playlists to a library and tracks to playlists and organise them.
|
| Version 1.0.0: Assignment released.
|
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cspotify.h"

/******************************************************************************/
// TODO: Add any other #defines you need.


/******************************************************************************/
// 'struct library' represents a library, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// playlists, though you may want to add other fields to it.
//
// You may choose to add or change fields in this struct.
struct library {
    struct playlist *head;
    struct playlist *selected;
};

// 'struct playlist' represents a playlist. 
// You may choose to add or change fields in this struct.
struct playlist {
    char name[MAX_LEN];
    int numTracks;
    struct track *tracks;
    struct playlist *next;
    struct playlist *back;
};

// 'struct trackLength' represents the length of a track. 
// You may choose to add or change fields in this struct.
struct trackLength {
    int minutes;
    int seconds;
};

// 'struct track' represents a track. 
// You may choose to add or change fields in this struct.
struct track {
    char title[MAX_LEN];
    char artist[MAX_LEN];
    struct trackLength length;
    struct track *next;
};

/******************************************************************************/
// TODO: Add any other structs you define here.


/******************************************************************************/
// TODO: Add prototypes for any extra functions you create here.
void soundex_encode(char plaintext[MAX_LEN], char code[5]);

// Function prototypes for helper functions. 
static void print_playlist(int number, char playlistName[MAX_LEN]);
static void print_selected_playlist(int number, char playlistName[MAX_LEN]);
static void print_track(char title[MAX_LEN], char artist[MAX_LEN], int minutes, int seconds);

/******************************************************************************/
// You need to implement the following functions.
// In other words, write code to make the function work as described 
// in cspotify.h

/*********
> STAGE 1
*********/

// Create a new Library and return a pointer to it.
Library create_library(void) {
    Library newLibrary = malloc(sizeof(struct library));
    newLibrary->head = NULL;
    newLibrary->selected = NULL;
    return newLibrary;
}

// Add a new Playlist to the Library.
int add_playlist(Library library, char playlistName[MAX_LEN]) {
    
    // Allocate memory for a new playlist and initialise the tracks to be empty.
    Playlist newPlaylist = malloc(sizeof(struct playlist));
    newPlaylist->numTracks = 0;
    newPlaylist->tracks = NULL;
    newPlaylist->next = NULL;
    newPlaylist->back = NULL;
    
    // Check that the name for the new playlist is alphanumeric by looping 
    // through name and checkingthat each value  is within the valid range 
    // of ascii values. If valid, copy the string into newPlaylist.
    int i = 0;
    while (playlistName[i] != '\0') {
        if (!isalnum(playlistName[i])) {
            return ERROR_INVALID_INPUTS;
        }
        i++;
    }
    strcpy(newPlaylist->name, playlistName);
   
    // Add the new playlist to the end of the current playlist.
    Playlist curr = library->head;
    Playlist prev = NULL;
    
    // Places playlist in library if library is empty.
    if (curr == NULL) {
        library->head = newPlaylist;
        library->selected = newPlaylist;
    } else if (curr != NULL) {
        // If not empty, loop through the linked list to find the end and 
        // insert new playlist at the end.
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
        }
        newPlaylist->back = prev;
        prev->next = newPlaylist;
    }
    
    return SUCCESS;
}

// Print out the Library.
void print_library(Library library) {
    
    Playlist curr = library->head;
    int i = 0;
    while (curr != NULL) {
        
        // If the playlist being printe is the currently selected one, 
        // use the print selected function. After printing each playlist, 
        // check if it contains tracks. If so, print the tracks.
        if (curr == library->selected) {
            print_selected_playlist(i, curr->name);
            Track currTrack = curr->tracks;
            while (currTrack != NULL) {
                print_track(currTrack->title, currTrack->artist, 
                (currTrack->length).minutes, (currTrack->length).seconds);
                currTrack = currTrack->next;
            }
        } else if (curr != library->selected) {
            print_playlist(i, curr->name);
            Track currTrack = curr->tracks;
            while (currTrack != NULL) {
                print_track(currTrack->title, currTrack->artist, 
                currTrack->length.minutes, currTrack->length.seconds);
                currTrack = currTrack->next;
            }
        }

        i++;
        curr = curr->next;
    }
}

// Rename the name of an existing Playlist.
int rename_playlist(Library library, char playlistName[MAX_LEN],
    char newPlaylistName[MAX_LEN]) {
    
    Playlist curr = library->head;
    // Loop through the library and look for the playlistName requested or end
    // if the end of the list is reached.
    int strsame = 0;
    while (curr != NULL && strsame == 0) {
        if (strcmp(curr->name, playlistName) == 0) {
            strsame = 1;
        } else {
            curr = curr->next;
        }
    }
    if (curr == NULL) {
        return ERROR_NOT_FOUND;
    }
    
    // Check each character of newPlaylistName to make sure it is alphanumeric. 
    int i = 0;
    while (newPlaylistName[i] != '\0') {
        if (!isalnum(newPlaylistName[i])) {
            return ERROR_INVALID_INPUTS;
        }
        i++;
    }
    
    // Replace the old playlist name with the new one.
    strcpy(curr->name, newPlaylistName);
    
    return SUCCESS;
}


/*********
> STAGE 2
*********/

// Selects the next Playlist in the Library.
void select_next_playlist(Library library) {
    // If library is empty, do nothing.
    if (library->head != NULL) {
        // If not the last item in list, move selected to next playlist.
        // If last, the next one would be the first playlist.
        if (library->selected->next != NULL) {
            library->selected = library->selected->next;
        } else if (library->selected->next == NULL) {
            library->selected = library->head;
        }
    }
}

// Selects the previous Playlist in the Library.
void select_previous_playlist(Library library) {
    // If library is empty, do nothing.
    if (library->head != NULL) {
        // If not the first item in list, move back a playlist.
        // If first playlist, previous will be last playlist.
        if (library->selected->back != NULL) {
            library->selected = library->selected->back;
        } else if (library->selected->back == NULL) {
            // Must select last playlist in library. Loop through until last.
            Playlist last = library->head;
            while (last->next != NULL) {
                last = last->next;
            }
            library->selected = last;
        }
    }
}

// Add a new Track to the selected Playlist.
int add_track(Library library, char title[MAX_LEN], char artist[MAX_LEN], 
    int trackLengthInSec, int position) {
    
    // Check that there are playlists in the library to add to.
    if (library->head == NULL) {
        return ERROR_NOT_FOUND;
    }
    Playlist currPlaylist = library->selected;
    
    // Create new track.
    Track newTrack = malloc(sizeof(struct track));
    
    // If track title is valid, copy into track details. Else return error.
    int iTit = 0;
    while (title[iTit] != '\0') {
        if (!isalnum(title[iTit])) {
            return ERROR_INVALID_INPUTS;
        }
        iTit++;
    }
    strcpy(newTrack->title, title);
    
    // If artist name is valid, copy into track details. Else return error.
    int iArt = 0;
    while (artist[iArt] != '\0') {
        if (!isalnum(artist[iArt])) {
            return ERROR_INVALID_INPUTS;
        }
        iArt++;
    }
    strcpy(newTrack->artist, artist);
    
    // If track length is  > 0 convert into minutes and seconds and insert 
    // into trackLength struct. Else return error.
    if (trackLengthInSec > 0) {
        int mins = trackLengthInSec / 60;
        int secs = trackLengthInSec % 60;
        newTrack->length.minutes = mins; //potential problem with access
        newTrack->length.seconds = secs; // of minutes and seconds
    } else {
        return ERROR_INVALID_INPUTS;
    }
    
    // Check that position isn't greater than current number of tracks
    // and not negative.
    if (position < 0 || position > currPlaylist->numTracks) {
        return ERROR_INVALID_INPUTS;
    }
    
    // If playlist is empty, add track in first position.
    if (currPlaylist->tracks == NULL) {
        currPlaylist->tracks = newTrack;
        newTrack->next = NULL;
    } else if (position == 0) { 
        // If adding to non-empty playlist in first position, replace tracks head.
        newTrack->next = currPlaylist->tracks;
        currPlaylist->tracks = newTrack;
    } else if (position > 0) {
        // Loop through playlist and insert after "position" number of tracks.
        Track currTrack = currPlaylist->tracks;
        Track prevTrack = NULL;
        int iPos = 0;
        while (iPos < position) {
            prevTrack = currTrack;
            currTrack = currTrack->next;
            iPos++;
        }
        newTrack->next = currTrack;
        prevTrack->next = newTrack;
    }
    currPlaylist->numTracks++;
    
    return SUCCESS;
}

// Calculate the total length of the selected Playlist in minutes and seconds.
void playlist_length(Library library, int *playlistMinutes, int *playlistSeconds) {
    // If library is empty, time is -1.
    if (library->selected == NULL) {
        *playlistMinutes = -1;
        *playlistSeconds = -1;
    } else {
        // Keep a running counter of time while looping through. Convert to 
        // seconds, add total and divide by 60 for minutes, modulus for seconds.
        Track currTrack = library->selected->tracks;
        int timeCounter = 0;
        while (currTrack != NULL) {
            timeCounter += currTrack->length.seconds;
            timeCounter += 60 * currTrack->length.minutes;
            currTrack = currTrack->next;
        }
        *playlistMinutes = timeCounter / 60;
        *playlistSeconds = timeCounter % 60;
    }
}


/*********
> STAGE 3
*********/

// Delete the first instance of the given track in the selected Playlist
// of the Library.
void delete_track(Library library, char track[MAX_LEN]) {
    // Check that a playlist exists
    if (library->head == NULL) {
        return;
    }
    Track currTrack = library->selected->tracks;
    Track prevTrack = NULL;
    // Loop through until match for track name is found.
    if (currTrack == NULL) {
        // Case for empty playlist 
        return;
    }
    while (currTrack != NULL) {
        if (strcmp(currTrack->title, track) == 0) {
            Track remTrack = currTrack;
            // If track being deleted is first track, point head of tracks
            // to next.
            if (prevTrack == NULL) {
                library->selected->tracks = currTrack->next;
            } else {
                prevTrack->next = currTrack->next;
            }
            free(remTrack);
            return;
        }
        prevTrack = currTrack;
        currTrack = currTrack->next; 
    }
    library->selected->numTracks--;
}

// Delete the selected Playlist and select the next Playlist in the Library.
void delete_playlist(Library library) {
    // Check that library is not empty
    if (library->head == NULL) {
        return;
    }
    Playlist remPlaylist = library->selected;
    // Loop through selected playlist to delete all tracks.
    while (remPlaylist->tracks != NULL) {
        Track remTrack = remPlaylist->tracks;
        remPlaylist->tracks = remPlaylist->tracks->next;
        free(remTrack);
    }
    // Now that the playlist is empty, delete the playlist. 
    // If it is the first playlist, change head and selected. If not, 
    // change selected.
    select_next_playlist(library);
    if (remPlaylist == library->head) {
        library->head = remPlaylist->next;
        // If that was not only playlist in library, change next node's
        // pointers.
        if (library->head != NULL) {
            library->head->back = NULL;
        }
    } else {
        Playlist prev = remPlaylist->back;
        prev->next = remPlaylist->next;
        // If the deleted playlist was not last in the list point back
        // pointer of next node at correct node.
        if (remPlaylist->next != NULL) {
            remPlaylist->next->back = prev;
        }
    }
    free(remPlaylist);
}

// Delete an entire Library and its associated Playlists and Tracks.
void delete_library(Library library) {
    while (library->head != NULL) {
        delete_playlist(library);
    }
    free(library);
}


/*********
> STAGE 4
*********/

// Cut the given track in selected Playlist and paste it into the given 
// destination Playlist.
int cut_and_paste_track(Library library, char trackTitle[MAX_LEN], 
    char destPlaylist[MAX_LEN]) {
    // Loop through playlists to find the requested one.
    Playlist currPlaylist = library->head;
    while (currPlaylist != NULL && 
           strcmp(currPlaylist->name, destPlaylist) != 0) {
        currPlaylist = currPlaylist->next;     
    }
    // If currPlaylist is NULL, either the library was empty or playlist
    // didn't exist. Return error. Otherwise currPlaylist is paste dest.
    if (currPlaylist == NULL) {
        return ERROR_NOT_FOUND;
    }
    
    
    // Loop through selected playlist to find requested track.
    Track currTrack = library->selected->tracks;
    Track prevTrack = NULL;
    Track cutTrack = NULL;
    while (currTrack != NULL && strcmp(currTrack->title, trackTitle) != 0) {
        prevTrack = currTrack;
        currTrack = currTrack->next;
    }
    cutTrack = currTrack;
    
    // If at the end of the loop, currTrack is NULL, either the playlist
    // was empty or the track was not found. Return error. Otherwise, track
    // was found and rest of tracks must be mended.
    if (currTrack == NULL) {
        return ERROR_NOT_FOUND;
    } else if (prevTrack == NULL){
        // If track is first in the list, make next new head.
        library->selected->tracks = currTrack->next;
    } else {
        prevTrack->next = currTrack->next;
    }
    
    // If destPlaylist is empty, paste into position 0.
    if (currPlaylist->tracks == NULL) {
        currPlaylist->tracks = cutTrack;
        cutTrack->next = NULL;
    } else {
        // Otherwise, loop through destPlaylist to get to the end and add track.
        Track destTracks = currPlaylist->tracks;
        while (destTracks->next != NULL) {
            destTracks = destTracks->next;
        }
        destTracks->next = cutTrack;
        cutTrack->next = NULL;
    }
    currPlaylist->numTracks++;
    library->selected->numTracks--;
    
    return SUCCESS;
}

// Print out all Tracks with artists that have the same Soundex Encoding 
// as the given artist.
void soundex_search(Library library, char artist[MAX_LEN]) {
    // Encode the artist name.
    char artistCode[5];
    soundex_encode(artist, artistCode);
    
    // Loop through library. If artist soundex matches 
    // given artist, print_track. 
    char compareCode[5];
    Playlist currPlaylist = library->head;
    while (currPlaylist != NULL) {
        Track currTrack = currPlaylist->tracks;
        while (currTrack != NULL) {
            soundex_encode(currTrack->artist, compareCode);
            if (strcmp(artistCode, compareCode) == 0) {
                print_track(currTrack->title, currTrack->artist, 
                (currTrack->length).minutes, (currTrack->length).seconds);
            }
            currTrack = currTrack->next;
        }
        currPlaylist = currPlaylist->next;
    }
}

/*********
> STAGE 5
*********/

// Move all Tracks matching the Soundex encoding of the given artist 
// to a new Playlist.
int add_filtered_playlist(Library library, char artist[MAX_LEN]) {
    // Check that requested artist name isnt already playlist 
    Playlist check = library->head;
    while (check != NULL) {
        if (strcmp(artist, check->name) == 0) {
            return ERROR_INVALID_INPUTS;
        }
        check = check->next;
    }
    // Check alphanumeric.    
    int i = 0;
    while (artist[i] != '\0') {
        if (!isalnum(artist[i])) {
            return ERROR_INVALID_INPUTS;
        }
        i++;
    }
    
    // Create a new playlist.
    add_playlist(library, artist);
    // It will be last in the library, so loop through library to find it.
    Playlist newPlaylist = library->head;
    while (newPlaylist->next != NULL) {
        newPlaylist = newPlaylist->next;
    }
    
    // Find all tracks with the same soundex code and cut and paste them into
    // the new playlist.
    char artistCode[5];
    soundex_encode(artist, artistCode);
    
    // Loop through tracks of each playlist. If artist soundex matches
    // requested artists, cut and paste track to newPlaylist.
    Playlist currPlaylist = library->head;
    Track destTracks = newPlaylist->tracks;
    while (currPlaylist->next != NULL) {
        Track currTrack = currPlaylist->tracks;
        Track prevTrack = NULL;
        while (currTrack != NULL) {
            char compareCode[5];
            soundex_encode(currTrack->artist, compareCode);
            if (strcmp(artistCode, compareCode) == 0) {
                Track cutTrack = currTrack;
                // Mend the playlist that is losing a track.
                if (prevTrack == NULL) {
                    currPlaylist->tracks = cutTrack->next;
                    currTrack = cutTrack->next;
                    // maybe make currTrack->next = cutTrack->next here
                } else {
                    prevTrack->next = currTrack->next;
                    currTrack = cutTrack->next;
                    // and here
                }
                // Paste track into newPlaylist.
                if (newPlaylist->tracks == NULL) {
                    newPlaylist->tracks = cutTrack;
                    destTracks = cutTrack;
                } else {
                    destTracks->next = cutTrack;
                    destTracks = cutTrack;
                }
                cutTrack->next = NULL;
                currPlaylist->numTracks--;
                newPlaylist->numTracks++;
            } else {
                prevTrack = currTrack;
                currTrack = currTrack->next;
            }
        }
        currPlaylist = currPlaylist->next;
    }
    
    return SUCCESS;
}

// Reorder the selected Playlist in the given order specified by the order array.
void reorder_playlist(Library library, int order[MAX_LEN], int length) {
    
    // if playlist is empty or only has one item, no reordering required.
    if (length < 2) {
        return;
    }
    
    // cycle through selected playlist and do a correct track orders.
    // keep doing this until order is correct.
    // reorder by swapping if prevTrack's position > currTrack's position
    // attach order array to the tracks in current orders
    // reorder both simultaneously to keep track of current order.
    Track currTrack = library->selected->tracks;
    Track prevTrack = NULL;
    int i = 0;
    int unordered = 1;
    while (unordered == 1) {
        // loop though list swapping tracks
        i = 0;
        currTrack = library->selected->tracks;
        prevTrack = NULL;
        while (currTrack->next != NULL && i < (length-1)) {
            if (order[i] > order[i+1]) {
                // swap corresponding items in linked list and array
                // this compares currTrack with currTrack->next
                // if first 2, swap tracks pointer.
                if (prevTrack == NULL) {
                    library->selected->tracks = currTrack->next;
                    currTrack->next = currTrack->next->next;
                    library->selected->tracks->next = currTrack;
                    prevTrack = library->selected->tracks;
                    int temp = order[i];
                    order[i] = order[i+1];
                    order[i+1] = temp;
                } else {
                    Track swapTrack = currTrack->next;
                    prevTrack->next = swapTrack;
                    currTrack->next = swapTrack->next;
                    swapTrack->next = currTrack;
                    int temp = order[i];
                    order[i] = order[i+1];
                    order[i+1] = temp;
                }
            } else {
                prevTrack = currTrack;
                currTrack = currTrack->next;
            }
            i++;
        }
        
        
        // check that the array is still unordered
        i = 0;
        unordered = 0;
        while (i < (length-1) && unordered == 0) {
            if (order[i] > order[i+1]) {
                unordered = 1;
            }
            i++;
        }
        
    }
    
}

/*****************
> Other Functions
*****************/

// Produce a string containing the Soundex encoding for a given string.
void soundex_encode(char artist[MAX_LEN], char code[5]) {
    int i = 0;
    
    char plaintext[MAX_LEN];
    strcpy(plaintext, artist);
    // The first character remains the same. Convert all to uppercase so ASCII
    // values can be compared without case differences.
    while (plaintext[i] != '\0') {
        plaintext[i] = toupper(plaintext[i]);
        i++;
    }
    // Loop through to store the values of each letter. When finding the
    // value of the next letter, if it is the same as the previous, 
    // do not store number and skip to next char of plaintext.
    // If there was a 0, instead of inserting a 0, make a note of the 0
    // so that numbers wont be merged if they do not correspond to 
    // adjacent letters.
    i = 0;
    int j = 0;
    int zeroed = 0;
    while (plaintext[i] != '\0' && j < 4) {
        if (plaintext[i] == 'A' || plaintext[i] == 'E' ||
                   plaintext[i] == 'I' || plaintext[i] == 'O' ||
                   plaintext[i] == 'U' || plaintext[i] == 'Y' ||
                   plaintext[i] == 'H' || plaintext[i] == 'W' ) {
            if (j == 0) {
                code[j] = '0';
                j++;
            }
            zeroed = 1;
        } else if (plaintext[i] == 'B' || plaintext[i] == 'F' ||
                   plaintext[i] == 'P' || plaintext[i] == 'V') {
            if (j == 0 || zeroed == 1 || code[j-1] != '1') {
                code[j] = '1';
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'C' || plaintext[i] == 'G' ||
                   plaintext[i] == 'J' || plaintext[i] == 'K' ||
                   plaintext[i] == 'Q' || plaintext[i] == 'S' ||
                   plaintext[i] == 'X' || plaintext[i] == 'Z') {
            if (j == 0 || zeroed == 1 || code[j-1] != '2') {
                code[j] = '2';
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'D' || plaintext[i] == 'T' ) {
            if (j == 0 || zeroed == 1 || code[j-1] != '3') {
                code[j] = '3';
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'L') {
            if (j == 0 || zeroed == 1 || code[j-1] != '4') {
                code[j] = '4';
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'M' || plaintext[i] == 'N' ) {
            if (j == 0 || zeroed == 1 || code[j-1] != '5') {
                code[j] = '5';
                j++;
                zeroed = 0;
            }
        } else if (plaintext[i] == 'R') {
            if (j == 0 || zeroed == 1 || code[j-1] != '6') {
                code[j] = '6';
                j++;
                zeroed = 0;
            }
        }
        i++;
    }
    // Make sure the first letter of code is the same as plaintext.
    code[0] = plaintext[0];
    // If there are less than 4 characters in the code after encoding,
    // fill in the rest as 0s, keeping last as null terminator.
    while (j < 4) {
        code[j] = '0';
        j++;
    }
    code[4] = '\0';
    
}

/*****************
> Helper Functions
*****************/

static void print_playlist(int number, char playlistName[MAX_LEN]) {
    printf("[ ] %d. %s\n", number, playlistName);
}

static void print_selected_playlist(int number, char playlistName[MAX_LEN]) {
    printf("[*] %d. %s\n", number, playlistName);
}

static void print_track(char title[MAX_LEN], char artist[MAX_LEN], int minutes, int seconds) {
    printf("       - %-32s    %-24s    %02d:%02d\n", title, artist, 
        minutes, seconds);
}
