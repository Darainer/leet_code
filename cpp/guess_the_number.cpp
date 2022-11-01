/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
//Sqrt search using modified binary search

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int correct_value{0};
    Solution(int value){
        correct_value = value;
    };
    int guessNumber(int n) {
        long lhs = 1;
        long rhs = n;
        long mid = lhs + (rhs-lhs)/2;
        int result{1};
        while(result!=0){
            mid = lhs + (rhs - lhs)/2;
            result = guess(mid);
            if(result == 1){
                rhs = mid-1;
            }
            else if(result ==-1){
                lhs = mid+1;
            }
        }
    return mid;
    }
private:
    int guess(int num){
        if (num == correct_value){return 0;}
        if (num < correct_value){return -1;}
        if (num > correct_value){return  1;}
    }    
};

int main()
{
    
    int max_value{10};
    int correct_value{6};
    Solution solution(correct_value);
    int output = solution.guessNumber(max_value);
    cout << output << endl;
}