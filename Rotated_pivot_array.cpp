//Search in Rotated Sorted Array
//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// idea 1: use brute force search to find the pivot (testing along the way for the target)
// could refine by searching from back and front at the same time (reduce the average run time)
// then use binary search to find the value in the sorted section
// is O(n) + O(logn) -> O(n) worst case
// idea 2: finding the pivot can be done O(logn), if we test to see if mid>end
// O(logn) + O(logn) -> O(logn) solution


#include <vector>
#include <iostream>
using namespace std;

class Solution_On {
public:
    int search(vector<int>& nums, int target) {
        int i=0;
        while(nums[i+1]> nums[i]){
            if(nums[i]== target){
                return i; //we found it on the way
            }
            i++;
        }
        //pivot found, was not in first part
        int lhs{i+1};
        int rhs= nums.size()-1;
        int mid = lhs + (rhs-lhs)/2;
        while(lhs<rhs){
            if (nums.at(mid) == target ){
                return mid;
            }
            else if (target < nums.at(mid)){
                rhs = mid;
            }
            else{
                lhs = mid;
            }
            mid = lhs + (rhs - lhs)/2;
        }   
        return -1;  //couldnt find it
        }  
};

class Solution_logn {
public:
    int search(vector<int>& nums, int target) {

        //find pivot by searching for smallest array element
        int lhs = 0;
        int rhs = nums.size() -1;
        int mid{0};
        while(lhs<rhs){
            mid = lhs + (rhs-lhs)/2;
            if(nums.at(mid) > nums.at(rhs)){
                lhs =  mid+1;
            }
            else{
                rhs = mid;
            }
        }
        // found pivot, now search for target value
        int pivot{lhs};
        if (target > nums.back()){  //if target is larger than end then search in first half
            lhs = 0;
            rhs = pivot;
        }
        else{
            lhs= pivot;
            rhs= nums.size()-1;
        }
        while(lhs<rhs){
            mid = lhs + (rhs - lhs)/2;
            if (nums.at(mid) == target ){
                return mid;
            }
            else if (target < nums.at(mid)){
                rhs = mid;
            }
            else{
                lhs = mid;
            }
            
        }   
        return -1;  //couldnt find it
        }  
};


struct Test
{
    Test(vector<int> numbersin, int target_in, int expected_output){
        numbers = numbersin;
        target = target_in;
        output = expected_output;

    }
    vector<int> numbers{};
    int target{};
    int output{};
};

int main()
{

Test test1({4,5,6,7,0,1,2},0,4);
Test test2({3,4,5,6,8,9,11,23,-1,0,1},0,9);
Solution_logn mysolution;
int output = mysolution.search(test1.numbers,test1.target);
cout << "output" << output << endl;
cout << "expected output" << test1.output << endl;
int output2 = mysolution.search(test2.numbers,test2.target);
cout << "output" << output2 << endl;
cout << "expected output" << test2.output << endl;
}

