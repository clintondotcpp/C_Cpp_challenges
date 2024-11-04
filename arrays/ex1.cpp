/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> newArray;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    newArray.push_back(i);
                    newArray.push_back(j);
                    return newArray;
                }
            }
        }
        return newArray;
    }

    void PrintArray(std::vector<int> myArray)
    {
        for (int i = 0; i < myArray.size(); i++)
        {
            std::cout << "{" << myArray[i] << " , " << "}" << std::endl;
        }
    }
};

int main()
{
    std::vector<int> myArray = {2,
                                7,
                                10,
                                5,
                                3,
                                8};
    Solution e;
    e.PrintArray(e.twoSum(myArray, 10));
}