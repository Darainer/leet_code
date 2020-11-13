//Fizz Buzz
//the classic

//find pivot index with equal sum on each side

#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> output{};
        for(int i= 1; i<=n+1 ; ++i){
        
            if( (i%3)== 0  && (i%5)==0){
                output.emplace_back("FizzBuzz");
            }    
            else if( (i%3) == 0){
                output.emplace_back("Fizz");
            }
            else if( (i%5) == 0){
                output.emplace_back("Buzz");
            }
            else {
                output.emplace_back(std::to_string(i));
            }

        }
        return output;
    }
};


int main()
{
    Solution mysolution;
    std::vector<string> output = mysolution.fizzBuzz(15);
    for(auto my_string : output){
        std::cout << my_string << std::endl;
    }
}