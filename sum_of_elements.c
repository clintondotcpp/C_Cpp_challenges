#include <stdio.h>

int SumOfElements(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

void Print(int array[], int size, int result)
{
    for (int i = 0; i < size; i++)
    {
        printf(" The sum of array[%d] - %d\n", i, array[i]);
    }
    printf("\n");
    printf("The sum of %d", result);
}

int main()
{
    int array[] = {23, 51, 41, 9, 100, 20, 11, 99};
    int size = sizeof(array) / sizeof(array[0]);
    int result = SumOfElements(array, size);
    Print(array, size, result);
    // printf("The sum of")
}