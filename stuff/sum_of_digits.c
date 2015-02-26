#include<stdio.h>
#include<inttypes.h>

uint_fast64_t sum_of_digits(int_fast64_t);

int main()
{
        uint_fast64_t sum = 0;
        int_fast64_t input = -2147483648;
        int_fast64_t input_copy = input;

        /*
         ** Check for negative numbers and if negative switch the sign.
         ** If the number is int_fast64_t_MIN then we cannot do anything.
         ** That number will cause wrong behaviour.
         */
        if (input < 0) {
                input = ~input + 1;
        }

        sum = sum_of_digits(input);

        do {
                sum = sum_of_digits(sum);
        } while (sum > 10);

        printf("The root sum of digits of %" PRIdFAST64 " is %" PRIdFAST64 "\n", input_copy, sum);

        return 0;
}

uint_fast64_t sum_of_digits(int_fast64_t in)
{
        uint_fast64_t sum = 0;

        for (; in > 0; ) {
                sum += (in % 10);
                in /= 10;
        }

        return sum;
}
