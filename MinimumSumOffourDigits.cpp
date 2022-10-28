
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
#include <algorithm>

using namespace std; 
using std::ostream;


class Solution {
public:
    int minimumSum(int num) {
    int digits[4];
        for (int i=0;i<4;i++)
        {
            digits[i]=num%10;
            num=num/10;
        }
    sort(begin(digits),end(digits));
    return 10*(digits[0]+digits[1])+digits[2]+digits[3];
    }


};

int main() {
    Solution s;
    int number = 4009;
    int result = s.minimumSum(number);
    cout << result << endl;
    return 0;
}