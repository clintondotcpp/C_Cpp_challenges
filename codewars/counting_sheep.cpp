#include <iostream>
#include <vector>

int count_sheep(std::vector<bool> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == true)
        {
            sum++;
        }
    }
    return sum;
}

bool checkForFactor(int base, int factor)
{
    if (base % factor == 0)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    std::vector<bool> boolArray = {true, false, true, false, true, true, true, false};
    int result = count_sheep(boolArray);
    std::cout << result << std::endl;

    std::cout << checkForFactor(6, 3) << std::endl;
}