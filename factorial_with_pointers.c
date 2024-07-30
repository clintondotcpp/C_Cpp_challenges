#include <stdio.h>

// how does a factorial work, 6! = 6 x 5 x 4 x 3 x 2 x 1
// implement a loop to count down from 6 to 1 and multiple a fact 1 by each figure
int factorial(int n)
{
    int fact = 1;

    for (int i = n; i >= 1; i--)
    {
        if (n < 1)
        {
            printf("Not a positive integer");
            break;
        }
        fact *= i;
    }
    return fact;
}

int main()
{
    int n = -1;
    int result = factorial(n);
    printf("The factorial of %d is: %d ", n, result);
}