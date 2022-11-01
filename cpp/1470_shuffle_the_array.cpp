class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>output(nums.size());
        for (int iterator = 0; iterator<n;iterator++ ){
            output[2*iterator]= nums[iterator];
            output[2*iterator+1] = nums[n + iterator];  
        }
        return output;
    }
};