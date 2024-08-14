#include <stdio.h>

void ReverseArray(int *array, int size)
{
    for (int i = size; i > 0; i--)
    {
        printf("{%d}", array[i]);
    }
}

int main()
{
    int array[] = {2, 34, 222, 109, 23, 15};
    int size = sizeof(array) / sizeof(array[0]);
    ReverseArray(array, size);
}