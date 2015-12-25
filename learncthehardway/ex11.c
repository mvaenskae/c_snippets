#include <stdio.h>

int main(int argc, char *argv[])
{
    // go through each string in argv

    int i = argc - 1;
    while(i > 0) {
        printf("arg %d: %s\n", i, argv[i]);
        --i;
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };

    int num_states = 4;
    i = num_states - 1; // watch for this
    while(i > -1) {
        printf("state %d: %s\n", i, states[i]);
        --i;
    }

    // Extra credit Q2
    char *copy[argc - 1];

    i = 1;
    while (i < argc) {
        // This assigns memory locations, not real char-for-char copy of the strings
        copy[i - 1] = argv[i];
        ++i;
    }

    i = i - 2;
    while (i > -1) {
        printf("copy[%d]: %s\n", i, copy[i]);
        --i;
    }

    return 0;
}
