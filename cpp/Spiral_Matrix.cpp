//Given an m x n matrix, return all elements of the matrix in spiral order.


#include <vector>
#include <array>
#include <iostream>
#include <algorithm>


using std::vector;

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

enum Direction{ RIGHT, DOWN, LEFT, UP}; 
    


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size()==0){return {};}
    
    Direction direction{RIGHT};
    int row_idx{0}, col_idx{0};
    int boundary_top{0}, boundary_bottom{static_cast<int>(matrix.size()-1)};
    int boundary_left{0}, boundary_right{static_cast<int>(matrix[0].size()-1)};
    vector<int> result{};
    result.push_back( matrix[row_idx][col_idx]);

    while(!(boundary_bottom <= boundary_top && boundary_left >= boundary_right)){  //test that the bounds have not fully converged
        switch(direction){
        case RIGHT :
            if(col_idx +1 <= boundary_right){
                col_idx++;
                result.push_back( matrix[row_idx][col_idx]);
            }
            else{
                direction = DOWN;
                boundary_top +=1;
            }
            break;
        case DOWN :
            if(row_idx+1 <= boundary_bottom){
                row_idx++;
                result.push_back( matrix[row_idx][col_idx]);
            }
            else{
                direction = LEFT;
                boundary_right -=1;  
            }
            break;
        case LEFT :
            if(col_idx -1 >= boundary_left){
                col_idx--;
                result.push_back( matrix[row_idx][col_idx]);
            }
            else{
                direction = UP;
                boundary_bottom -=1;
            }
            break;
        case UP :
            if(row_idx -1 >= boundary_top){
                row_idx--;
                result.push_back( matrix[row_idx][col_idx]); 
            }
            else{
                direction = RIGHT;
                boundary_left +=1;
            }
            break;
        } //switch direction
}
    return result;
};  

};  //Solution

int main(){
    std::vector<std::vector<int>> Input {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    //std::vector<int> Output_ans {1,2,3,4,8,12,11,10,9,5,6,7};
    print_utils::print_matrix(Input);
    Solution mysolution{};
    std::vector<int> answer = mysolution.spiralOrder(Input);
    print_utils::print_vector(answer);

    return 0;
};