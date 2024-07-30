#include <iostream>

void bubbleSort(int array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        // flag to detect any swap is there or not
        bool swapped = false;
        // compare two adjacent elements
        // change > to < to sort in descending order
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i] < array[i + 1])
            {

                // swapping occures if elements
                // are not in the intended order
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
    int array[] = {200, 11, 27, 18, 35, 111, 82, 3, 888, 29993, 5323, 22222, 44, 99};
    int size = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, size);
    Print(array, size);
}