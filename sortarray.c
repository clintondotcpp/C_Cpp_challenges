#include <stdio.h>

int *array(int *my_array)
{
    int n, largest;
    printf("How many elements do you want in the array?: ");
    scanf("%d", &n);
    *my_array = (int)malloc(sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (my_array[i] > largest)
        {
            largest = my_array[i];
        }
    }
    return my_array;
    free(my_array);
}

int main()
{
    /* int *local_array;
     *array(local_array);
     for (int i = 0; i < *arr)*/
}