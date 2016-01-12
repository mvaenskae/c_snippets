#include <stdio.h>
#include <string.h>

void print_index(int*, char**, int);
void print_startpointers(int*, char**, int);
void print_pointers_as_arrays(int*, char**, int);
void print_stupid(int*, char**, int);

int main(int argc, char *argv[])
{
    // create two arrays we care about
    int ages[] = {23, 43, 12, 89, 2};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int name_count = sizeof(names) / sizeof(names[0]);
    int name_length = 0;
    int i = 0;
    int j = 0;

    // first way using indexing
    /*for(i = 0; i < count; i++) {
        printf("%s has %d years alive.\n",
                names[i], ages[i]);
    }
    printf("---\n");*/

    print_index(ages, names, count);
    printf("---\n");

    // second way using pointers
    /*for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(cur_name+i), *(cur_age+i));
    }
    printf("---\n");*/

    print_startpointers(ages, names, count);
    printf("---\n");

    // third way, pointers are just arrays
    /*for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
                cur_name[i], cur_age[i]);
    }
    printf("---\n");*/

    print_pointers_as_arrays(ages, names, count);
    printf("---\n");

    // fourth way with pointers in a stupid complex way
    /*for(cur_name = names, cur_age = ages;
            (cur_age - ages) < count;
            cur_name++, cur_age++)
    {
        printf("%s lived %d years so far.\n",
                *cur_name, *cur_age);
    }
    printf("---\n");*/
    print_stupid(ages, names, count);
    printf("---\n");

    // Extra credit
    for (i = 0; i < name_count; ++i) {
        printf("%s(%p)\n", names[i], &names[i]);
        name_length = strlen(names[i]);
        
        for (j = 0; j < name_length; ++j) {
            printf("\t%c(%p)\n",*((names[i]) + j), (names[i] + j));
        }
    }

    printf("+++\n");

    for (i = 0; i < count; ++i) {
        printf("%d(%p)\n", ages[i], &ages[i]);
    }

    return 0;
}

void print_index(int *ages, char **names, int count)
{
    for (int i = 0; i < count; ++i) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }
}

void print_startpointers(int *ages, char **names, int count)
{
    int *age = ages;
    char **name = names;

    for (int i = 0; i < count; ++i) {
        printf("%s is %d years old.\n", *(name+i), *(age+i));
    }
}

void print_pointers_as_arrays(int *ages, char **names, int count)
{
    int *age = ages;
    char **name = names;

    for (int i = 0; i < count; ++i) {
        printf("%s is %d years old again.\n", name[i], age[i]);
    }
}

void print_stupid(int *ages, char **names, int count)
{
    int *age = ages;
    char **name = name;

    for (name = names, age = ages; (age - ages) < count; name++, age++) {
        printf("%s lived %d years so far.\n", *name, *age);
    }
}
