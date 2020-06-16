//first blind attempt on binary search before checking optimal implementation

#include <vector>
#include <iostream>
using namespace std;

//binary search
class MyBinarySearch
{
public:
    int binary_search(vector<int> &input, int key)
    {
        int left_pointer = 0;
        int right_pointer = input.size() - 1;
        int middle_pointer = (input.size() - 1) / 2;

        //iteratively search
        while (key != input.at(middle_pointer)){
            if (middle_pointer == left_pointer){
                if (input.at(right_pointer) == key){
                    middle_pointer = right_pointer;
                }
                else{
                    middle_pointer = -1;
                }
                break;
            }
            if (middle_pointer == right_pointer){
                if (input.at(left_pointer) == key){
                    middle_pointer = left_pointer;
                }
                else{
                    middle_pointer = -1;
                }
                break;
            }
            bounded_search(input, left_pointer, right_pointer, middle_pointer, key);
        }
        return middle_pointer;
    }

private:
    void bounded_search(vector<int> &input, int &left_pointer, int &right_pointer, int &middle_pointer, int &key)
    {
        if (key < input.at(middle_pointer))
        {
            right_pointer = middle_pointer;
        }
        else if (key > input.at(middle_pointer))
        {
            left_pointer = middle_pointer;
        }
        middle_pointer = left_pointer + (right_pointer - left_pointer) / 2;
    }
};

int main()
{
    vector<int> input{-4, -1, 6, 7, 11, 14, 17, 19, 25, 100, 200};
    int keys{13};
    MyBinarySearch search;
    int output = search.binary_search(input, keys);
    cout << output << endl;
}