// 1512. Number of Good Pairs
// Given an array of integers nums.
// A pair (i,j) is called good if nums[i] == nums[j] and i < j.
// Return the number of good pairs.

// Example 1:
// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

// Example 2:
// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

// Example 3:
// Input: nums = [1,2,3]
// Output: 0

// first solution: two pointer method... loops which get smaller since j(start)= i(start)+1

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int i{0},j{0},count{0};
        for(int i = 0; i<nums.size()-1;i++){
            for(int j= i+1; j<nums.size();j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
        }
    return count;
    }
};
int main(){
    Solution my_sol;
    vector<int> input{1,2,3,1,1,3}; 
    std::cout << my_sol.numIdenticalPairs(input) << std::endl;
}