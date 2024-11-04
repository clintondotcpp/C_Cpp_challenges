#include <iostream>
#include <vector>

int square_sum(const std::vector<int> &numbers)
{
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i] * numbers[i];
    }

    return sum;
}

int main()
{
    const std::vector<int> &array = {2, 4, 6, 8, 10};
    int result = square_sum(array);
    std::cout << result << std::endl;
}