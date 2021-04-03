//find pivot index with equal sum on each side

#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        //precompute the sum as a new vector (tradeoff space requirement for more speed)
        vector<int> nums_sum{nums};
        int working_sum{0};
        for (int i{0}; i < nums.size(); ++i){
            working_sum += nums[i];
            nums_sum[i] = working_sum;
        }
        
        //move pivot from left to right (should take left most occurance)
        int LHS{0};
        int RHS{0};
        for(int pivot{0}; pivot< nums.size(); ++pivot){
            if(pivot==0){
                LHS = 0;
            }
            else{
                LHS = nums_sum[pivot-1];
                }
            RHS = nums_sum[nums.size()-1] - nums_sum[pivot];  // need to remove the pivot value
            if(LHS==RHS){
                return pivot;
            }
        }
        return -1;
    }
};


int main()
{
    vector<int> nums{1,7,3,6,5,6};
    Solution mysolution;
    int pivot = mysolution.pivotIndex(nums);
    std::cout << "pivot value =" << pivot  << std::endl;
    std::cout << "expected pivot = 3";
}