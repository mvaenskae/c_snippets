#include <stdio.h>

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int offset = 'a' - 'A';

    for (int arg_index = 1; arg_index < argc; ++arg_index) {
        int i, converted;
        char letter;
        for(i = 0, converted = 0, letter = 0; argv[arg_index][i] != '\0';
                i++, converted = 0) {
            letter = argv[arg_index][i];

            if (letter >= 'A' && letter <= 'Z' ) {
                letter += offset;
                converted = 1;
            }

            switch(letter) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    printf("[%d][%d]: '%c'(%d)\n", arg_index, i, letter, converted);
                    break;
                case 'y':
                    if(i > 2) {
                        // it's only sometimes Y
                        printf("[%d][%d]: '%c'(%d)\n", arg_index, i, letter, converted);
                    }
                    // Doesn't matter if inside if as well, if is no loop.
                    break;

                default:
                    printf("[%d][%d]: %c(%d) is not a vowel\n", 
                            arg_index, i, letter, converted);
            }
        }
    }

    return 0;
}
