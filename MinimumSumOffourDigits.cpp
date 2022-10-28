
/* Example 1:

Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

Example 2:

Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.


Constraints:
1000 <= num <= 9999

Solution

1. Sort the digits in ascending order
2. add to both bins one at a time
3. return the int
*/

#include <ostream>
#include <iostream>
#include <list>

using namespace std; 
using std::ostream;


class Solution {
public:
    int minimumSum(int num) {
    std::list<int> digits = split_integer(num);
    digits.sort();
    
    int first= digits.front() * 10;
    digits.pop_front();
    int second = digits.front() * 10;
    digits.pop_front();
    first += digits.front();
    digits.pop_front();
    second += digits.front();
    return first + second;

    };
    std::list<int> split_integer(int number){
        std::list<int> digits{};
        while (number >= 0){   // also want the leading zero
            if (number == 0){ 
                break;
            }
            int digit = number%10;
            digits.push_back(digit);
            number /= 10;
            }
        return digits;
    }
};

int main() {
    Solution s;
    int number = 4009;
    int result = s.minimumSum(number);
    cout << result << endl;
    return 0;
}