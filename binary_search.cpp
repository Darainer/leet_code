//first blind attempt on binary search before checking optimal implementation

#include <vector>
#include <iostream>
using namespace std;

//binary search
class MyBinarySearch
{
public:
    int search(vector<int>& nums, int target)
    {
        int left_pointer = 0;
        int right_pointer = nums.size() - 1;
        int middle_pointer = right_pointer / 2;

        //iteratively search
        while (target != nums.at(middle_pointer)){
            if (left_pointer== right_pointer){
                middle_pointer = -1;
                break;
            }
            bounded_search(nums, left_pointer, right_pointer, middle_pointer, target);
        }
        return middle_pointer;
    }

private:
    void bounded_search(vector<int> &nums, int &left_pointer, int &right_pointer, int &middle_pointer, int &target)
    {
        if (target < nums.at(middle_pointer))
        {
            right_pointer = middle_pointer-1;
        }
        else if (target > nums.at(middle_pointer))
        {
            left_pointer = middle_pointer+1;
        }
        middle_pointer = left_pointer + (right_pointer - left_pointer) / 2;
    }
};

int main()
{
    //vector<int> nums{-4, -1, 6, 7, 11, 14, 17, 19, 25, 100, 200};
    vector<int> nums{2,5};
    int targets{2};
    MyBinarySearch search;
    int output = search.search(nums, targets);
    cout << output << endl;
}