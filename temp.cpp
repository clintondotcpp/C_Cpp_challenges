#include <iostream>

void Bubblesort(int array[], int size)
{
    bool swapped = false;
    // for loop to iterate through the array
    for (int step = 0; step < size - 1; ++step)
    { // for loop to compare adjacent elements
        for (int i = 0; i < size - step - 1; ++i)
        {

            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void Print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " " << std::endl;
    }
}

int main()
{
    int array[] = {100, 23, 44, 71, 28, 90, 17, 111, 23, 71, 23, 23, 28, 90, 90, 90};
    int size = sizeof(array) / sizeof(array[0]);
    Bubblesort(array, size);
    Print(array, size);
}