#include <stdio.h>

// Write a program in C to calculate the length of a string using a pointer.

// declare string
// set it to a pointer
// iterate through

int main()
{
    int counter = 0;
    char str[] = "Hello World!"; // string literal
    char *ptr;
    ptr = str; // set pointer to string

    int i = 0;
    while (ptr[i] != '\0')
    {
        counter++;
        i++;
    }

    printf("This is the length of the string: %d\n ", counter);
    return 0;
}
