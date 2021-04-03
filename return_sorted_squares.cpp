
#include <vector>
#include <iostream>
using namespace std;


int square(int in){
 return in*in;
}

// nums is sorted but can contain negatives
bool return_sorted_square_list(vector<int>& nums, vector<int>& output){
    int lhs = 0;
    int rhs = output.size()-1;
    int output_idx = output.size()-1;      //fill from the end
    while(lhs<=rhs){                       // if lhs==rhs we still return the numbe
    if (square(nums.at(lhs)) >= square(nums.at(rhs)) ){
        output[output_idx] = square(nums.at(lhs));
        output_idx--;
        lhs++;
    }
    else if (square(nums.at(lhs)) < square(nums.at(rhs)) ){
        output[output_idx] = square(nums.at(rhs));
        output_idx--;
        rhs--;
    }
}   
return 0;  //if successful (output is updated)
}

int main()
{
    vector<int> input{-9, -2, 0, 2, 3};  
    vector<int> solution{0, 4, 4, 9, 81};
    vector<int> output;
    output.resize(input.size());
    bool ok = return_sorted_square_list(input,output);
    if (ok){
        for (auto i : output){
            cout << i << endl;
            }
    }
}
