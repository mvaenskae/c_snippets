#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void bogosort(int *arr, size_t size);

void bogosort(int *arr, size_t size)
{
START:
    for (size_t i = 0; i < size; ++i) {
        int rng = open("/dev/urandom", O_RDONLY);
        size_t rand;
        ssize_t err = read(rng, (size_t *) &rand, 1);
        if (err < 0) {
            printf("ERROR!");
            return;
        }
        close(rng);
        rand = ((rand % size) + size) % size;
        if (rand != i) { 
            arr[i] ^= arr[rand];
            arr[rand] ^= arr[i];
            arr[i] ^= arr[rand];
        }
    }

    for (size_t i = 0; i < (size - 1); ++i)
        if (arr[i] > arr[i+1]) {
            goto START;
        }
}
