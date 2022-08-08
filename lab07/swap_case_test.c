// Function to test your swap_case function.
// swap_case.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
 
#include <stdio.h>

#define MEETS_SPEC 1
#define DOES_NOT_MEET_SPEC 0

int swap_case(int character);
int test_lower_to_upper(void);
int test_upper_to_lower(void);
int test_non_alphabetical(void);


int test_lower_to_upper(void) {
    // TODO: call `swap_case` to test if it turns lowercase letters to uppercase.
    char character = 'a';
    character = swap_case(character);
    if (character != 'A') {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}

int test_upper_to_lower(void) {
    // TODO: call `swap_case` to test if it turns uppercase letters to lowercase.
    char character = 'A';
    character = swap_case(character);
    if (character != 'a') {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}

int test_non_alphabetical(void) {
    // TODO: call `swap_case` to test if it doesn't affect non-alphabetical characters.
    char character = '@';
    character = swap_case(character);
    if (character != '@') {
        return DOES_NOT_MEET_SPEC;
    }
    
    return MEETS_SPEC;
}


//////////////////////////////////////////////////////////////////////////
// NOTE: The below function won't be marked! You can use it for testing //
//////////////////////////////////////////////////////////////////////////

int swap_case(int character) {
    if (character >= 'A' && character <= 'Z') {
        character = character - 'A' + 97;
    } else if (character >= 'a' && character <= 'z') {
        character = character - 'a' + 65;
    }
    return character;
}

//////////////////////////////////////////////////////////////////////////
// NOTE: DO NOT EDIT BELOW THIS COMMENT!                                //
//////////////////////////////////////////////////////////////////////////

int main(void) {

    printf("Testing turning an lowercase into uppercase: ");
    if (test_lower_to_upper() == MEETS_SPEC) {
        printf("MEETS SPEC\n");
    } else {
        printf("DOES NOT MEET SPEC\n");
    }

    printf("Testing turning an uppercase into lowercase: ");
    if (test_upper_to_lower() == MEETS_SPEC) {
        printf("MEETS SPEC\n");
    } else {
        printf("DOES NOT MEET SPEC\n");
    }

    printf("Testing a non-alphabetical character not changing: ");
    if (test_non_alphabetical() == MEETS_SPEC) {
        printf("MEETS SPEC\n");
    } else {
        printf("DOES NOT MEET SPEC\n");
    }

    return 0;
}

