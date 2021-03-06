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

//solution: start from the end of the nums1 vector. 
// use pointers to ensure we add all the values of both vectors without needing to (repeatedly) shift values of nums1
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3

#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int next_value_p = nums1.size()-1;

        while(next_value_p >=0){
            if(p1<0){
                nums1[next_value_p] = nums2[p2];
                p2--;
            }
            else if(p2<0){
                nums1[next_value_p] = nums1[p1];
                p1--;
            }
            else if(nums1[p1] < nums2[p2]){
                nums1[next_value_p] = nums2[p2];
                p2--;
            }
            else if( nums1[p1] >= nums2[p2]){
                nums1[next_value_p] = nums1[p1];
                p1--;
            }
            next_value_p--;
        }
    }
};

int main(){
    vector<int> nums{};
    for(int i = 0; i< 100;i++){
        nums.push_back(i);
    }
    // vector<int> nums1{1,2,3,0,0,0};
    // vector<int> nums2{2,5,6};       
    // int m = 3; 
    // int n = nums2.size();
    vector<int> nums1{0};
    vector<int> nums2{1};       
    int m = 0; 
    int n = nums2.size();

    Solution mySolution;
    mySolution.merge(nums1,m, nums2, n);
    for(int i = 0; i< nums1.size(); i++){
        cout << nums1[i];
    }
    cout << endl;
    return 0;
};