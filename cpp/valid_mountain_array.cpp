// Given an array A of integers, return true if and only if it is a valid mountain array.

// Recall that A is a mountain array if and only if:

// A.length >= 3
// There exists some i with 0 < i < A.length - 1 such that:
// A[0] < A[1] < ... A[i-1] < A[i]
// A[i] > A[i+1] > ... > A[A.length - 1]

#include <vector>
#include <iostream>
using namespace std; 

class Solution{    //
    public:
    bool validMountainArray(vector<int>& A) {
        bool isAMountainArray{false};
        //phase 1 check for increasing
        int i =0;
        int N = A.size()-1;
        while(A[i+1]>A[i] && i<N){
            i++;
        }
        //[Phase 2 check for decreasing    
        if (i ==0 || i == N){
            isAMountainArray = false;
        }
        else{        
            while(A[i+1]<A[i] && i<N){
                i++;
            }
            isAMountainArray = (i == N);
        }
     
    return isAMountainArray;  // if we made it to the end then it is true
    }
};

class Solution2{    //
    public:
    bool validMountainArray(vector<int>& A) {
        bool isAMountainArray{true};
        int mountain_top= A.size()-1;
        //phase 1 check for increasing
        for(int i=0; i<=A.size()-2;i++){
            if(!(A[i+1]>A[i])){
                mountain_top=i;       //mountain top
                break;
            }
        }    
        //[Phase 2 check for decreasing    
        if (mountain_top ==0 || mountain_top == A.size()-1){
            isAMountainArray = false;
        }
        else{        
            for(int j= mountain_top; j<= A.size()-2; j++){
               if(!(A[j+1]<A[j])){
                   isAMountainArray = false;
                }
            }
        } 
    return isAMountainArray;  // if we made it to the end then it is true
    }
};


int main(){
    vector<int> nums1 = {0,3,2,1};//{0,0,1,1,1,2,2,3,3,4};  //{2,1};//
    Solution mysolution;
    bool sol = mysolution.validMountainArray(nums1);
    std::cout << "valid= "<< sol <<std::endl;

    return 0;
};