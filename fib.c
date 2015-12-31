/* fib.c - generate Fibonacci numbers. */

#include <stdio.h>
/* Fib(94) is too big for unsigned long long on my machine. */
#define SIZE 94

/* Using a global array to store the fibs. 
 * Must initialize to zero for function to work. */
unsigned long long int FIBS[SIZE] = {0, 1};

unsigned long long int fib(int n);

int main(void)
{
    int i, len = SIZE;

    fib(SIZE-1);
    
    /* Display the numbers. */
    for (i = 0; i < len; i++)
        printf("Fib %d is %llu.\n", i, FIBS[i]);

    return 0;
}

/* Recursive function. Avoids too much work by checking
 * for fibs already computed. */
unsigned long long int fib(int n)
{
    if (n < 2)
        return n;
    if (FIBS[n])
        return FIBS[n];
    FIBS[n] = fib(n-1) + fib(n-2);
    return FIBS[n];
}
