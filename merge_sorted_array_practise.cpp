// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:

// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.
// Example:

// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

// Output: [1,2,2,3,5,6]
 

// Constraints:

// -10^9 <= nums1[i], nums2[i] <= 10^9
// nums1.length == m + n
// nums2.length == n

//merging into 1. 
//step 1: find the insertion place with binary search
//step 2: move the rest of nums1 across to perform the insertion

#include <vector>
#include <iostream>

using namespace std;

int find_value(vector<int>& nums, int target_val){
    //setup a binary search in the nums vector
    if(target_val>nums.back() || target_val< nums.front()){
        return -1;}
    int LHS = 0;
    int RHS = nums.size()-1;
    while( LHS < RHS){
        int mid = (LHS + RHS)/2;
        if(target_val == nums[mid]){
            return mid;
        }
        else if(target_val < nums[mid]){
            RHS = mid;
        }
        else if(target_val > nums[mid]){
            LHS = mid;
        }
    }
    return -1;
}

int find_index_to_insert(vector<int>& nums, int target_val, int LHS, int RHS){
    if(target_val > nums[RHS]){
        return RHS+1;
    }

    if(target_val < nums.front()){
        return LHS;
    }
    int mid;
    while( LHS < RHS){
        mid = (LHS + RHS)/2;
        if(target_val == nums[mid]){
            return mid;
        }
        else if(target_val < nums[mid]){
            RHS = mid;
        }
        else if(target_val > nums[mid]){
            LHS = mid;
        }
    }
    return mid;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lhs = 0;
        int rhs = m-1;
        for(int i = 0; i<n; i++){
            int index = find_index_to_insert(nums1, nums2[i],lhs, rhs);
            int j{};
            for(j = rhs; j>=index; j--){     // need to go through backwards to avoid overwriting. 
                nums1[j+1] = nums1[j];      // problem states that the array has enough space for the
            }
            nums1[index] = nums2[i];
            lhs = index+1;              // since the array is sorted, we only start looking to the RHS of the current index
            rhs +=1;                  //we have inserted a value so need to extend the rhs 
        }
    }
};

int main(){
    vector<int> nums{};
    for(int i = 0; i< 100;i++){
        nums.push_back(i);
    }
    std::cout << find_value(nums, 88) <<std::endl;
    vector<int> nums1{0}; //vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};       
    int m = 3; 
    int n = nums2.size();
    Solution mySolution;
    mySolution.merge(nums1,m, nums2, n);
    for(int i = 0; i< nums1.size(); i++){
        cout << nums1[i];
    }
    cout << endl;
}