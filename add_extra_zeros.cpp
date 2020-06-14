#include <vector>
#include <iostream>
#include <queue>
using namespace std; 

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int iterator{0};
        int zero_counter{0};
        queue<int> items_to_shift{};
        //save elements in queue
        while(iterator != arr.size()){
            if(arr[iterator]==0){
                items_to_shift.push(arr[iterator]);
                if(iterator!=arr.size()-1){       // edge case is final value is zero
                    items_to_shift.push(0); 
                    zero_counter++;
                    }
                iterator++;
            }
            else{     //arr[iterator] != 0
                items_to_shift.push(arr[iterator]);
                iterator++;
            }
        }
        //overwrite array until end
        for(int it = 0; it<=arr.size();it++){
            arr[it] = items_to_shift.front();
            items_to_shift.pop();
        }
    }
};

int main(){
    vector<int> arr{1,0,2,3,0,4,5,0};
    Solution mysolution;
    mysolution.duplicateZeros(arr);
    for (auto i : arr){
    std::cout << i << std::endl;}
    return 0;
}

// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
        
//         int iterator{0};
//         queue<int> items_to_shift{}};
//         while(iterator != arr.size()){
//             if(arr[iterator]!=0)
//                 if(items_to_shift.empty() ){                     //never seen a zero, move along
//                     iterator++;
//                 }
//                 else(){                                         // have things in the queue to shift
//                     items_to_shift.push_back(arr[iterator]);
//                     arr[iterator] = items_to_shift.pop_front();
//                     //iterator++;  //case of two consecutive zeros
//                 }

//             else if(arr[iterator] == 0){                           //zero, add another
//                 iterator++;
//                 items_to_shift.push_back(arr[iterator]);
//                 arr[iterator]=0;
//                 iterator++;
//             }
//         }    
// };