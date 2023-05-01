#include <stdio.h>
#include "functions.h"

#define F(a, b) a + b // Replace F(1,2) with 1+2

int main(void)
{
    int a = 2;
    int b = 5;
    printf("%d", sum(a, b));

    return 0;
}