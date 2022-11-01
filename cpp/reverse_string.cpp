// Write a function that reverses a string. The input string is given as an array of characters char[].

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// You may assume all the characters consist of printable ascii characters.

 

// Example 1:

// Input: ['h','e','l','l','o']
// Output: ['o','l','l','e','h']
// Example 2:

// Input: ['H','a','n','n','a','h']
// Output: ['h','a','n','n','a','H']

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int p1 = 0;
        int p2 = s.size()-1;
        while(p1<p2){
            char temp_left = s[p1];
            char temp_right = s[p2];
            s[p1] = temp_right;
            s[p2] = temp_left;
            p1++;
            p2--;
        }
    }
};

void print(const vector<char>& s ){
    for(auto element : s){
    cout << element << " ";
    }
    cout << endl;
}

int main() {
    vector<char> s = {'H','a','n','n','a','h'};
    print(s);
    Solution sol;
    sol.reverseString(s);
    print(s);
}