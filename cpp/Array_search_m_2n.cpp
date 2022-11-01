// Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
// More formally check if there exists two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]

#include <vector>
#include <iostream>
using namespace std; 

class Solution{    //
    public:
    bool checkIfExist(vector<int>& arr) {
        bool DoesExist{false};
        for (int i = 0; i<=arr.size()-1;i++){
            for(int j=0; j<= arr.size()-1;j++){
                if(i!=j && arr[i]== 2*arr[j]){
                    std::cout<< arr[i] << arr[j] << std::endl;
                    DoesExist = true;
                    return DoesExist;
                }
            }
        }
    return DoesExist;
    }
};


int main(){
    vector<int> nums1 = {1,2,3,1};//{0,0,1,1,1,2,2,3,3,4};
    Solution mysolution;
    bool sol = mysolution.checkIfExist(nums1);
    std::cout << "element number= "<< sol <<std::endl;
    for (auto i : nums1){
        std::cout << i << std::endl;
        }
    return 0;
};