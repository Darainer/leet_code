#include <vector>
#include <iostream>
using namespace std; 


class solution1{    //makes many copies where 
    public:
    int removeElement(vector<int>& nums, int val){
        int i{0}; //running iterator for last non val entry
        for(int j = 0; j<= nums.size()-1; j++){
            if(nums[j]!= val){
                if (i!=j){          //added compare to avoid unnecessary copies (for integer not really needed)
                nums[i] = nums[j];              
                }
                i++;
            }
        }
        return i;
    }
};

class solution2{   //changes the order of the elements!!
    public:
    int removeElement(vector<int>& nums, int val){
        int i{0}; //running iterator for last non val entry
        int j {nums.size()};
        while(i<j){
            if(nums[i]== val){
                nums[i] = nums[j-1];      
                j--;
            }
            else{
                i++;
            }
        }
        return i;
    }
};

int main(){
    vector<int> nums1 = {1,2,3,4,5}; int m = 2;
    solution2 mysolution;
    int ses = mysolution.removeElement(nums1,m);
    std::cout << "new length = "<< ses <<std::endl;
    for (auto i : nums1){
        std::cout << i << std::endl;
        }
    return 0;
};