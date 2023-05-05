#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=R0qIYWo8igs&list=PLA1FTfKBAEX4hblYoH6mnq0zsie2w6Wif&index=26

void do_something(void *ptr)
{
    int *int_ptr = ptr;

    for (int i = 0; i < 10; i++)
        int_ptr[i] = 10 - i;

    for (int i = 0; i < 10; i++)
        printf("a[%d] = %d\n", i, int_ptr[i]);
    printf("\n");
}

int main(void)
{

    // assigns memory, no init
    int *a = malloc(sizeof(int) * 10);

    // assigns memory, all init to 0
    int *b = calloc(10, sizeof(int));

    do_something(a);
    do_something(b);

    free(a);
    free(b);

    return 0;
}