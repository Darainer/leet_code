// Remove Duplicates from Sorted Array
// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.

// Example 2:
// Given nums = [0,0,1,1,1,2,2,3,3,4],
// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
// It doesn't matter what values are set beyond the returned length.


// approach
// step through from front (is sorted). need to maintain two pointers, write to and write from which skips all the duplicates. return the write to pointer

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){return 0;}
        int write_idx{0};
        int read_idx{1};
        while(read_idx< nums.size()){
            if (nums[read_idx]== nums[write_idx]){   //case 1: read value is a duplicate, step over it without moving the write pointer
                read_idx++;
            }
            else                                    //case 2: the value is not a duplicate
            {
                if(write_idx +1 != read_idx){
                    nums[write_idx+1]= nums[read_idx];  //only copy if not the same value
                }
                read_idx++;
                write_idx++;
            }
        }
        return write_idx +1;  // return the size (last unique index +1)
    }
};



int main(){

    //vector<int> arr{0,0,1,1,1,2,2,3,3,4};
    vector<int> arr{1,1,2};
    Solution mySol{};
    for(int i = 0; i<arr.size(); i++){
       std::cout<< arr.at(i) <<  "  ";    
    }
    std::cout<<std::endl;
    int output = mySol.removeDuplicates(arr);
    for(int i = 0; i<arr.size(); i++){
        std::cout<< arr.at(i) <<  "  ";    
    }
    std::cout<<std::endl;
    std::cout << "length is =" << output<< std::endl;
    return 0;
}