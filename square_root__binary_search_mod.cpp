//Sqrt search using modified binary search

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int mySqrt(int x) {
        //input is set of all integers [1,x]
        //2*2 < sqrt(x) <  right 
    if (x== 0){return x;}
    long left = 1;
    long right = x;
    long middle = left + (right - left)/2;
        while(left!=middle){
            if (x >=middle*middle && (x< (middle+1)*(middle+1)) ){
                return middle;
            }
            else if (x > middle*middle){
                left = middle;
            }
            else{
                right = middle;
            }
            middle = left + (right - left)/2;

        }
    return middle;
    }
};

int main()
{
    int target{100003};
    Solution solution;
    int output = solution.mySqrt(target);
    cout << output << endl;
}