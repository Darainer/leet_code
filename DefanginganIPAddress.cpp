#include <ostream>
#include <string>
#include <iostream>

using namespace std; 
using std::ostream;

class Solution {
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
    string address = "10.1.1.1";
    string result = s.defangIPaddr(address);
    cout << result << endl;
    return 0;
}