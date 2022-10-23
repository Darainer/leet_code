#include <ostream>
#include <string>
#include <iostream>

using namespace std; 
using std::ostream;


class Solution {
public:
    string defangIPaddr(string address) {
        string answer;
        answer.reserve(address.length() + 6); // 6 is constant for IP addresses
        for(auto i=0; i< address.length();  ++i ){
            if(address.at(i) == '.' ) {         // use .at(i) for better error handling
                answer.append("[.]");  
            }
            else {
                answer.push_back(address.at(i));
            }
        }
        return address;  
        }
    };



class Solution_old {
public:
    string defangIPaddr(string address) {

        for(auto i=0; i< address.length();  ++i ){
            if(address.at(i) == '.' ) {         // use .at(i) for better error handling
                address.replace(i, 1, "[.]");  // remove only the . 
                i+=2;   // skip over the new characters
            }
        }
        return address;  
        }
    };


int main() {
    Solution s;
    string address = "192.102.10.1";
    string result = s.defangIPaddr(address);
    cout << result << endl;
    return 0;
}

// learnings
// push_back() is the method single chars, append() for strings or multiple chars
// if the size of the string is known in advance, use reserve() to allocate the memory.
// wont make much difference for small strings like in this case, but can be significant for large strings
// making a new string is more efficient than replacing the old one in this case (see Solution_old)
