#include<vector>
#include<iostream>

class Solution {
public:
    //count the positive sloped periods in the stock ticker
    int maxProfit(vector<int>& prices) {
        int i{0};
        int maxProfit{0};
        while (i<prices.size()-1){
            if(prices[i]<prices[i+1]){
                maxProfit += prices[i+1]-prices[i];
            }
            i++;
        }
    return maxProfit;
    }
};

int main(){
  Solution my_profits;
  vector<int> testcase1{7,1,5,3,6,4};
  int output = my_profits.maxProfit(testcase1);
  std::cout<< "max profit = " << output << std::endl;   
