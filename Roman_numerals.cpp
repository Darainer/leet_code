/* Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58

*/

#include <iostream>
#include <iterator>
#include<string>
using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int answer=0;

        for(int i = s.length()-1; i>=0; i--){
            
            if(s[i]== 'I'){
                answer+=1;
            }

            else if(s[i] == 'V'){
                if(i!=0 && s[i-1]== 'I'){
                    answer+= 4;
                    i=i-1;  //move back further
                }
                else{
                    answer +=5;
                }
            }

            else if(s[i] == 'X'){
                if(i!=0 && s[i-1]== 'I'){
                    answer+= 9;
                    i=i-1;  //move back further
                }
                else{
                    answer+= 10;
                }
            }
            
            else if(s[i] == 'L'){
                if(i!=0 && s[i-1]== 'X'){
                    answer+= 40;
                    i=i-1;  //move back further
                }
                else{
                    answer += 50;
                }
            }

            else if(s[i] == 'C'){
                if(i!=0 && s[i-1]== 'X'){
                    answer+= 90;
                    i=i-1;  //move back further
                }
                else{
                    answer += 100;
                }
            }

            else if(s[i] == 'D'){
                if(i!=0 && s[i-1]== 'C'){
                    answer+= 400;
                    i=i-1;  //move back further
                }
                else{
                    answer += 500;
                }
            }

            else if(s[i] == 'M'){
                if(i!=0 && s[i-1]== 'C'){
                    answer+= 900;
                    i=i-1;  //move back further
                }
                else{
                    answer += 1000;
                }
            }
        }   
        return answer;
    }
};



int main(){
    Solution s;
    string roman_str = "LVIII";
    int answer = s.romanToInt( roman_str);
    cout << answer << endl;
}