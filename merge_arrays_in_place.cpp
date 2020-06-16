#include <vector>
#include <iostream>
#include <queue>
using namespace std; 


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ap1{0};
        int ap2{0};

        queue<int> original_nums1;
        for(int num_it = 0; num_it <= m-1; num_it++ ){
            original_nums1.push(nums1[num_it]);
        }
        bool take_1{true};
        while(ap1<nums1.size()){  //n
            // case 1: both arrays have valid numbers to copy
            if(original_nums1.size()>0 && ap2 < n){
                if(original_nums1.front()<=nums2[ap2]){
                        take_1 = true;
                }
                else{take_1 = false;}
            }
            //case 2: only num1 numbers valid
            else if(original_nums1.size() >0 && ap2==n){
                take_1= true;
            }
            //case 3: only num2 numbers valid
            else if(original_nums1.size() ==0 && ap2< n){
                take_1 = false;
            }

            if(take_1){           
                nums1[ap1] = original_nums1.front();
                original_nums1.pop();
                ap1++;
            }
            else{  //take from 2
                nums1[ap1] = nums2[ap2];
                ap1++, ap2++;
                }
        }
        
    }
};

int main(){
    vector<int> nums1 = {1,2,3,0,0,0}; int m = 3;
    vector<int> nums2 = {2,5,6}; int  n = 3;
    Solution mysolution;
    mysolution.merge(nums1,m,nums2,n);
    for (auto i : nums1){
        std::cout << i << std::endl;
        }
    return 0;
};