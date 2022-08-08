/*******************************************************************************
> CSpotify - 20T3 COMP1511 Assignment 2
| test_cspotify.c
|
| zID: z5312476
| Name: Lisa Guo
| Date: November 2020
|
| Version 1.0.0: Assignment released.
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_cspotify.h"
#include "cspotify.h"
#include "capture.h"

/*********************************************
> Test Functions
| These tests are explained in test_cspotify.h
*********************************************/

/*********
> STAGE 1
*********/

// Test function for 'add_playlist'
void test_add_playlist(void) {

    // Test 1: Does add_playlist return SUCCESS and add 
    // when adding one Playlist with a valid name?
    Library testLibrary = create_library();

    int result = add_playlist(testLibrary, "Favourites");
    if (result != SUCCESS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    char printText[10000];
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (!string_contains(printText, "Favourites")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: Does add_playlist return ERROR_INVALID_INPUTS
    // and not add the playlist into the Library
    // when trying to add a Playlist with an invalid name?
    
    // Try adding a non-alphanumeric playlist and if it doesnt
    // present the correct error message, fail.
    result = add_playlist(testLibrary, "@*#$");
    if (result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 3: Does add_playlist return ERROR_INVALID_INPUTS if multiple 
    // playlists are added at once?
    result = add_playlist(testLibrary, "play list");
    if (result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}

// Test function for 'rename_playlist'
void test_rename_playlist(void) {
    // Test 1: Does rename_playlist return ERROR_NOT_FOUND 
    // when trying to rename a playlist when the Library is empty?
    
    Library testLibrary = create_library();
    int result = rename_playlist(testLibrary, "Favourites", "STR8BANGERZZ");
    if (result != ERROR_NOT_FOUND) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: Does rename_playlist successfully
    // rename a Playlist when a valid new Playlist name is given to 
    // rename an existing Playlist in the Library?

    add_playlist(testLibrary, "Favourites");
    result = rename_playlist(testLibrary, "Favourites", "STR8BANGERZZ");
    if (result != SUCCESS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Check the output is new name.
    char printText[10000];
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (!string_contains(printText, "STR8BANGERZZ")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Test 3: Does rename_playlist return ERROR_INVALID_INPUTS if given
    // non-alphanumeric inputs when renaming a playlist in the library?
    
    add_playlist(testLibrary, "MemeS");
    result = rename_playlist(testLibrary, "MemeS", "@!#$");
    if (result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    

    printf("MEETS SPEC\n");
}


/*********
> STAGE 2
*********/

// Test function for 'add_track'
void test_add_track(void) {
    // Test 1: Does add_track successfully add 
    // multiple (more than 3 Tracks) Tracks 
    // to the Library?
    
    // Add some valid tracks to a playlist.
    Library testLibrary = create_library();
    add_playlist(testLibrary, "TESTTRACKS");
    int result0 = add_track(testLibrary, "Track0", "Artist0", 127, 0);
    int result1 = add_track(testLibrary, "Track1", "Artist1", 257, 1);
    int result2 = add_track(testLibrary, "Track2", "Artist2", 173, 2);
    int result3 = add_track(testLibrary, "Track3", "Artist3", 132, 3);
    int result4 = add_track(testLibrary, "Track4", "Artist4", 149, 4);
    int result5 = add_track(testLibrary, "Track5", "Artist5", 260, 0);
    int result6 = add_track(testLibrary, "Track6", "Artist6", 147, 1);
    int result7 = add_track(testLibrary, "Track7", "Artist7", 279, 2);
    int result8 = add_track(testLibrary, "Track8", "Artist8", 345, 3);
    int result9 = add_track(testLibrary, "Track9", "Artist9", 198, 4);
    
    // If any of them are not successful, fail.
    if (result0 != SUCCESS || result1 != SUCCESS ||
        result2 != SUCCESS || result3 != SUCCESS ||
        result4 != SUCCESS || result5 != SUCCESS ||
        result6 != SUCCESS || result7 != SUCCESS ||
        result8 != SUCCESS || result9 != SUCCESS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: Does add_track return ERROR_NOT_FOUND when library is empty?
    Library testLibrary1 = create_library();
    int result10 = add_track(testLibrary1, "MyWay", "Frank", 257, 0);
    
    if (result10 != ERROR_NOT_FOUND) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Test 3: Does add_track return ERROR_INVALID_INPUTS if title, artist, 
    // position, length is not valid?
    Library testLibrary2 = create_library();
    add_playlist(testLibrary2, "Chill");
    int result11 = add_track(testLibrary2, "Th@tsL!fe", "Frank", 257, 0);
    int result12 = add_track(testLibrary2, "ThatsLife", "Fr@nk)", 257, 0);
    int result13 = add_track(testLibrary2, "ThatsLife", "Frank", 257, -5);
    int result14 = add_track(testLibrary2, "ThatsLife", "Frank", 257, 50);
    int result15 = add_track(testLibrary2, "ThatsLife", "Frank", 0, 0);
    int result16 = add_track(testLibrary2, "ThatsLife", "Frank", -257, 0);
    
    
    if (result11 != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (result12 != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (result13 != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (result14 != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (result15 != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (result16 != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    printf("MEETS SPEC\n");
}

// Test function for 'playlist_length'
void test_playlist_length(void) {
    // Test 1: Does playlist_length work for Tracks 
    // with lengths greater than 60 seconds?
    Library testLibrary = create_library();
    add_playlist(testLibrary, "90s");
    add_track(testLibrary, "Numb", "LinkinPark", 185, 0);
    int playlistMinutes, playlistSeconds;
    playlist_length(testLibrary, &playlistMinutes, &playlistSeconds);
    
    if (playlistMinutes != 3 || playlistSeconds != 5) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
   
    // Test 2: Does playlist_length work for multiple tracks with lengths
    // greater than 60 seconds?
    add_track(testLibrary, "NewDivide", "LinkinPark", 268, 0);
    add_track(testLibrary, "ChirpChirp", "Bird", 62, 0);
    add_track(testLibrary, "Crrrrr", "Cricket", 65, 0);
    playlist_length(testLibrary, &playlistMinutes, &playlistSeconds);
    if (playlistMinutes != 9 || playlistSeconds != 40) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Test 3: Does playlist_length store length as -1
    // when library is empty?
    Library testLibrary1 = create_library();
    int mins, secs;
    playlist_length(testLibrary1, &mins, &secs);
    if (mins != -1 || secs != -1) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Test 4: Does playlist_length store length as 0
    // when playlist is empty?
    add_playlist(testLibrary1, "Empty");
    playlist_length(testLibrary1, &mins, &secs);
    if (mins != 0 || secs != 0) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Test 5: If the track is short, does the minutes remain at 0?
    add_track(testLibrary1, "Crrrrr", "Cricket", 5, 0);
    playlist_length(testLibrary1, &mins, &secs);
    if (mins != 0 || secs != 5) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    printf("MEETS SPEC\n");
}


/*********
> STAGE 3
*********/

// Test function for 'delete_playlist'
void test_delete_playlist(void) {
    // Test 1: Does delete_playlist work if
    // the selected Playlist is the first Playlist
    // in the Library?
    Library testLibrary = create_library();
    add_playlist(testLibrary, "DELETE");
    delete_playlist(testLibrary);
    
    char printText[10000];
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (string_contains(printText, "DELETE")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: Does delete_playlist work for deleting multiple
    // playlists in a row?
    Library testLibrary1 = create_library();
    add_playlist(testLibrary1, "DELETE");
    add_playlist(testLibrary1, "REMOVE");
    add_playlist(testLibrary1, "BEGONE");
    add_playlist(testLibrary1, "RID");
    delete_playlist(testLibrary1);
    delete_playlist(testLibrary1);
    delete_playlist(testLibrary1);
    delete_playlist(testLibrary1);
    
    CAPTURE(print_library(testLibrary1), printText, 10000);
    if (string_contains(printText, "DELETE")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    if (string_contains(printText, "REMOVE")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    if (string_contains(printText, "BEGONE")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    if (string_contains(printText, "RID")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}


/*********
> STAGE 4
*********/

// Test function for 'soundex_search'
void test_soundex_search(void) {
    // Test 1: Can soundex_search successfully find one track
    // with same artist soundex code?
    Library testLibrary = create_library();
    add_playlist(testLibrary, "SOUNDEX");
    add_track(testLibrary, "MyWay", "Frank", 257, 0);
    
    
    char printText[10000];
    CAPTURE(soundex_search(testLibrary, "FRANK"), printText, 10000);
    if (!string_contains(printText, "Frank")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    
    // Test 2: Can soundex_search successfully find multiple tracks
    // with same artist code over multiple playlists and output
    // in original character case?
    Library testLibrary1 = create_library();
    add_playlist(testLibrary1, "SOUNDEX");
    add_track(testLibrary1, "MyWay", "Frank", 257, 0);
    add_track(testLibrary1, "OldManRiver", "frAnK", 173, 1);
    add_playlist(testLibrary1, "SOUNDEX2");
    select_next_playlist(testLibrary1);
    add_track(testLibrary1, "Star", "Perry", 132, 0);
    add_track(testLibrary1, "Evening", "fRomC", 149, 1);
    
    char printText1[10000];
    CAPTURE(soundex_search(testLibrary1, "FRANK"), printText1, 10000);
    if (!string_contains(printText1, "Frank")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (!string_contains(printText1, "frAnK")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    } else if (!string_contains(printText1, "fRomC")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}


/*********
> EXTRA
*********/

//  Your extra tests (Not worth marks)
void extra_tests(void) {
    // TODO: Add any extra tests you have here
    
    // Tests for cut_and_paste_track function.
    // Test 1: Can the function successfully cut and paste a track,
    // when given fully valid inputs?
    
    printf("MEETS SPEC\n");
}

/*****************
> Helper Functions
*****************/

// Find the string 'needle' in 'haystack'
int string_contains(char *haystack, char *needle) {
    return strstr(haystack, needle) != NULL;
}
