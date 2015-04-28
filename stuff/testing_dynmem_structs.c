#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>

#define PRINT_OPAQUE_STRUCT(p)  print_mem((p), sizeof(*(p)))

void print_mem(void const *vp, size_t n)
{
    unsigned char const *p = vp;
    for (size_t i=0; i<n; i++)
        printf("%02X ", p[i]);
    putchar('\n');
}

struct test {
        uint64_t d;
        char e[3];
        int test;
        char e[128];
};

struct teststruct {
        struct test a;

        struct test** b;
        
        uint64_t testcount;

        uint64_t testcount2;
};

int main(void)
{
        int *r;

        struct teststruct *x;
        struct test *y;

        x = malloc (sizeof (*x));
        y = malloc (sizeof (*y));
        printf("Before memset\n");
        PRINT_OPAQUE_STRUCT(x);
        PRINT_OPAQUE_STRUCT(y);

        memset (x, 0, sizeof (*x));
        memset (y, 0, sizeof (*y));
        printf("After memset\n");
        PRINT_OPAQUE_STRUCT(x);
        PRINT_OPAQUE_STRUCT(y);
        
        y->d = 0x0123456789ABCDEF;
        strncpy(y->e, "iii", 3);
        printf("Setting struct test\n");
        PRINT_OPAQUE_STRUCT(x);
        PRINT_OPAQUE_STRUCT(y);
        
        x->testcount = 64;
        x->testcount2 = 0xFFFFFFFFFFFFFFFE;
        //x->a = malloc (sizeof (x->a));
        x->b = malloc (10 * sizeof (*(x->b)));
        printf("Setting struct teststruct\n");
        PRINT_OPAQUE_STRUCT(x);
        //PRINT_OPAQUE_STRUCT(x->a);
        PRINT_OPAQUE_STRUCT(x->b);
        PRINT_OPAQUE_STRUCT(y);

        x->a = *y;
        *((x->b) + 2) = y;
        printf("Assiging test to teststruct\n");
        PRINT_OPAQUE_STRUCT(x);
        //PRINT_OPAQUE_STRUCT(x->a);
        PRINT_OPAQUE_STRUCT(*((x->b) + 2));
        PRINT_OPAQUE_STRUCT(y);

        r = malloc(sizeof(*r));
        *r = 32;

        printf("%lX(%X), *%lX(%X)\n", sizeof(r), r, sizeof(*r), *r);
        printf("%lx(%x), *%lx(%x), &%lx(%x)\n", sizeof(x), x, sizeof(*x), *x, sizeof(&x), &x);

        free(r);
        //free(x->a);
        free(x->b);
        free(x);
        return 0;
}
