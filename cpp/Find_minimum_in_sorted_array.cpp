//Find Minimum in Rotated Sorted Array

// Solution
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

// Find the minimum element.

// You may assume no duplicate exists in the array.

// Example 1:

// Input: [3,4,5,1,2]
// Output: 1
// Example 2:

// Input: [4,5,6,7,0,1,2]

#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int left{0}, right = nums.size() - 1, middle{0};
        //sorted array case
        if (nums[left] < nums[right])
        {
            return nums[left];
        }
        //find pivot minimum with bin search
        while (right > left +1)
        { // last test will be on the middle, set to right and then returned
            middle = left + (right - left) / 2;
            if (nums.at(left) > nums.at(middle))
            { // //test is always, that the left is greater than middle.
                right = middle;
            }
            else
            { //pivot is to the right of the middle
                left = middle;
            }
        }
        return nums.at(right);
    }
};

int main()
{
    //vector<int> input{4,5,6,7,0,1,2};
    //vector<int> input{4,5,6,7,8,0,1,2,3};
    //vector<int> input{3,4,5,1,2};
    vector<int> input{4, 5, 6, 7, 0, 1, 2};
    //vector<int> input{2,1};
    Solution mysolution;
    int output = mysolution.findMin(input);
    cout << output << endl;
}
