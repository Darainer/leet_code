// Good morning! Here's your coding interview problem for today.

// This problem was asked by Facebook.

// Given an N by N matrix, rotate it by 90 degrees clockwise.

// For example, given the following matrix:

// [[1, 2, 3],
//  [4, 5, 6],
//  [7, 8, 9]]
// you should return:

// [[7, 4, 1],
//  [8, 5, 2],
//  [9, 6, 3]]
// Follow-up: What if you couldn't use any extra space?

#include <vector>
#include <array>
#include <iostream>

class Matrix{
    std::vector<std::vector<int>> m_matrix;
    public:
    Matrix(std::vector<std::vector<int>> &input){
    m_matrix = input;
    }
    void print(){
        for(int i = 0; i< m_matrix.size(); i++){
            for (int j = 0 ; j <  m_matrix[0].size(); j ++){
            std::cout << " " << m_matrix[i][j];
            }
        std::cout << std::endl;
        }   
    }
    std::vector<std::vector<int>> rotate(){
        if ( m_matrix.size() != m_matrix[0].size()){
            std::cout<< "not a square matrix";
            return std::vector<std::vector<int>> {};
        }
        
        int n = m_matrix.size();
        
        
        //preallocate the vector (could use array)
    // Initializing the 2-D vector
    std::vector<std::vector<int>> rotated_matrix(n, std::vector<int> (n, 0)) ;
        // std::vector< std::vector<int> > rotated_matrix{};
        // rotated_matrix.reserve(n);
        // for(auto row : m_matrix){
        //      row.reserve(n);
        // }

        for(int i = 0; i< n; i++){
            for(int j = 0; j< n; j++){
                rotated_matrix[j][n-1-i] = m_matrix[i][j];
            }
            // for (int j = 0 ; j <  m_matrix[0].size(); j ++){
            //     rotated_matrix[i][j] = m_matrix[j][i];
        }
        return rotated_matrix;
    }

};


int main(){
    std::vector<std::vector<int>> input{};
    input = {{1, 2, 3}, {4, 5 , 6}, {7 , 8, 9}};
    Matrix mymatrix(input);
    mymatrix.print();
    std::cout << std::endl;
    std::vector<std::vector<int>> rotated = mymatrix.rotate();
    Matrix myrotmatrix(rotated);
    myrotmatrix.print();

    return 0;
}