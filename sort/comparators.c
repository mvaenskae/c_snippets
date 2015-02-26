#include <inttypes.h>


int comparator(const void *a, const void *b)
{
    //Select the proper sorting function somehow...
    if (typeof(a) == (char *)) {
        return compare_string(a, b);
    }
    if (typeof(*a) == (char)) { 
        return compare_char(*a, *b);
    }
    if (typeof(*a) == (int)) {
        return compare_int(*a, *b);
    }
    if ((typeof(*a) == (float)) || (typeof(*a) == (double))) {
        return compare_float(*a, *b);
    }
    else 
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
