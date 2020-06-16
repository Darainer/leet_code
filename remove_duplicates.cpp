#include <vector>
#include <iostream>
using namespace std; 

class solution{    //
    public:
    int removeDuplicates(vector<int>& nums) {
        int i{0};
        for (int j= 1; j<=nums.size()-1;j++){
            if(nums[i]!=nums[j]){
                nums[i+1]= nums[j];
                i++;
            }
        }
        return i+1;
    }
};


int main(){
    vector<int> nums1 = {1,1,2};//{0,0,1,1,1,2,2,3,3,4};
    solution mysolution;
    int ses = mysolution.removeDuplicates(nums1);
    std::cout << "new length = "<< ses <<std::endl;
    for (auto i : nums1){
        std::cout << i << std::endl;
        }
    return 0;
};