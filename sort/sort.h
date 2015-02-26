/*
 ** This header file is a collection of function prototypes for all the sorting functions defined in their corresponding .c files. This collection is being expanded and completed as time and pleasure allows.
 ** Mickey Vänskä
 */

void bogosort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

void mergesort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
