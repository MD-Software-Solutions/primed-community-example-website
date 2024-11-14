/*
Soham M. Desai
Cmdr. Schenk
11/6/24
Process
*/

// Some libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// Entry point
int main(int argc, char *argv[]) {

    // Set vars
    char target_char = argv[1][0], *file_name;
    int word_count = 0, hit_target = 0, inside_word = 0, ch;

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./process [letter] [filename]\n");
        return 1;
    }

    // Check if the first argument is a single alphabetic character
    if (argv[1][1] != '\0' || !isalpha(argv[1][0])) {
        printf("Usage: ./process [letter] [filename]\n");
        return 1;
    }

    // Get target character and file name into vars
    target_char = argv[1][0];
    file_name = argv[2];

    // Open the file, check if it does not exixt and if so send error
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // fgetc(file) gets teh character and stores to ch.
    // While runs till we are at end of file
    while ((ch = fgetc(file)) != EOF) {

        // If it is our target, get it in
        if (ch == target_char) {
            hit_target++;
        }

        // Check if it is a " " or punctuation
        if (isspace(ch) || ispunct(ch)) {
            if (inside_word) {
                word_count++;
                inside_word = 0;
            }
        }

        // We're inside a word
        else {
            inside_word = 1;
        }
    }

    // Close
    fclose(file);

    // Provide with info
    printf("There are %d words in this file, and the letter '%c' occurs %d times.\n", word_count, target_char, hit_target);

    // Exit with 0
    return 0;
}
