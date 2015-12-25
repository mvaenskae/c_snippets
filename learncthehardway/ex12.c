#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if(argc == 1) {
        printf("No arguments supplied.\n");

    } else if (argc == 2) {
        printf("You only have one argument. Supply more.\n");

    } else if(argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for(i = 0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");

    } else {
        printf("You have too many arguments. Supply less.\n");

    }

    return 0;
}
