#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int bogosort(int *arr, size_t size);

int bogosort(int *arr, size_t size)
{
    for (size_t j = 0; j < (size - 1); ++j)
        if (arr[j] > arr[j+1]) {
            for (size_t i = 0; i < size; ++i) {
                int rng = open("/dev/urandom", O_RDONLY);
                if (rng == -1) {
                    return 1;
                }
                size_t rand;
                ssize_t err = read(rng, (size_t *) &rand, 1);
                if (err < 0) {
                    return 1;
                }
                close(rng);
                rand = ((rand % size) + size) % size; // Too lazy to rework a % b to ((a - b) * (a / b))
                if (rand != i) {
                    arr[i] ^= arr[rand];
                    arr[rand] ^= arr[i];
                    arr[i] ^= arr[rand];
                }
            }
            j = -1;
        }
    return 0;
}

int main(void)
{
    //int arr[10] = {2, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[8] = {2, 1, 3, 4, 5, 7, 9, 10};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    int_fast8_t err = bogosort(arr, size);
    if (err) {
        printf("Encountered error!\n");
        return err;
    } else {
    for (size_t i = 0; i < size; ++i)
        printf("%i ", arr[i]);
    putchar(10);
    }
        return 0;
}
