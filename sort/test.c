#include <inttypes.h>
#include <stdio.h>
#include "sort.h"

typedef struct merchandise {
    char name[16];
    char* uuid;
    char *description;
    uint64_t type;
    double price;
    struct distributor;
} merc;

typedef struct third_party {
    char name[32];
    char *website;
    char *country;
    uint8_t reliability;
} TP;


struct merc list[]={
    "First", 1, 20, 300, 4000, 50000,
    "Second", 2, 30, 400, 5000, 60000,
    "Third", 3, 40, 500, 6000, 70000,
    "Fourth", 4, 50, 600, 7000, 80000,
    "Fifth", 5, 60, 700, 8000, 90000,
    "Sixth", 6, 70, 800, 9000, 100000,
    "Seventh", 7, 80, 900, 10000, 110000,
    "Eighth", 8, 90, 1000, 11000, 120000,
    "Ninth", 9, 100, 1100, 12000, 130000,
};

int comparator(const void *a, const void *b)
{
    MT *_a = (MT *) a;
    MT *_b = (MT *) b;
    if(typeof())
}

/*
 ** This function compares two strings and returns 3 types of values. These are:
 ** <0 (first argument is smaller)
 ** =0 (both are the same value)
 ** >0 (second argument is smaller)
 */
int compare_string(const char *a, const char *b)
{
    return strcmp(*a, *b);
}

/*
 ** This function compares two chars and returns 3 types of values. These are:
 ** <0 (first argument is smaller)
 ** =0 (both are the same value)
 ** >0 (second argument is smaller)
 */
int compare_char(const char a, const char b)
{
    return a - b;
}

/* This function compares two whole numbers and returns 3 types of values. These are:
 ** <0 (first argument is smaller)
 ** =0 (both are the same value)
 ** >0 (second argument is smaller)
 */
int compare_ints(const void a, const void b)
{
    return (long long) a - (long long) b;
}

/* This function compares two floating points and returns 3 types of values. These are:
 ** <0 (first argument is smaller)
 ** =0 (both are the same value)
 ** >0 (second argument is smaller)
 */
int compare_floats(const void a, const void b)
{
    if ((double) a > (double) b) {
        return 1;
    }
    if ((double) b > (double) a) {
        return -1;
    }
    return 0;
}

/*
 ** No idea what this does, copying from an exercise.
 */
void apply(MT *arr, int nrec, void (*fp)(void *prec, *arg), void *arg)
{
    for (int i = 0; i < nrec; ++i) {
        fp(&arr[i], arg);
    }
}


int main(int argc, void **argv)
{
    return 0;
}
