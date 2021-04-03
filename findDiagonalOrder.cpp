// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

// Example:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]

// Output:  [1,2,4,7,5,3,6,8,9]

#include <type_traits>
#include <vector>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

namespace print_utils{

 const void print_matrix(vector<vector<int>> const &matrix) {
        for(auto const &i: matrix){
            for (auto const &j: i){
            std::cout << " " << j;
            }
        std::cout << std::endl;
        }
    };

void print_vector(std::vector<int> const &input){
    for (auto const& i: input) {
        std::cout << i << " " << std::endl;
    };
};

};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    if(matrix.size()==0){return {};}
    vector<vector<int>> Result{};
    int row_idx = 0;
    int col_idx = 0;

    //traverse the top row
     for (col_idx = 0; col_idx <= matrix[0].size()-1; col_idx++){
        Result.push_back({});
        fill_diagonal( matrix, Result.back(), 0, col_idx);
    }
    // go down the last column
    for ( row_idx = 1; row_idx <= matrix.size()-1; ++row_idx){
        Result.push_back({});
        fill_diagonal( matrix, Result.back(), row_idx, matrix[0].size()-1);
    }

    // flatten into a single vector for output
    vector<int> output;
    bool invert{false};
    for(auto& item : Result){
        invert = !invert;
        if(invert){
            std::reverse(item.begin(), item.end());   //reverse every second element
        }
        for(auto& value : item){
            output.push_back(value);
        }
    }
    return output;
    }

private: 
    void fill_diagonal(vector<vector<int>>& matrix,vector<int>& input, int row, int col){
        while( col >= 0 && (row <= matrix.size()-1) ){
        input.push_back(matrix[row][col]);
        col -=1;
        row +=1;
        }
    }
};

int main(){
    //std::vector<std::vector<int>> input{{1, 2, 3}, {4, 5 , 6}, {7 , 8, 9}};
    std::vector<std::vector<int>> input{{3}, {2}};
    print_utils::print_matrix(input);
    Solution mysolution{};
    std::vector<int> answer = mysolution.findDiagonalOrder(input);
    print_utils::print_vector(answer);

    return 0;
}