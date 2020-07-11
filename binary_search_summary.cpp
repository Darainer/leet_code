//Summary of binary search problems

/*
basic structure is this loop where the vector nums is a SORTED array of items (here integers)
*/
#include<vector>
using namespace std;

int binary_search(vector<int> &nums, int lhs, int rhs, int target)
{
    while (lhs <= rhs)                  // variation point 1: can be necessary to use lhs<rhs or other
    {                                    // if lhs==rhs we still test and return mid or -1
        int mid = lhs + (rhs - lhs) / 2; // calculate mid first, so that it is only needed once
        if (nums.at(mid) == target)     // variation point 2: the test is a favourite to change
        {
            return mid;
        }
        else if (nums.at(mid) < target)
        {
            lhs = mid + 1;   // variation point3: eliminting mid from the range (mid +1) or not 
        }
        else
        {
            rhs = mid - 1;
        }
    }
    return -1; //couldnt find it
}

/*
Variations of questions here can be 
Variation point 2: can be repeated values, can be arithmetic test like in the sqrt problem
-pivot or shift in the array such that it is not completely sorted (search for pivot with binary search)

variation point 3: if we have a test with the single value, we have just tested mid, so can eliminate from range for lhs and rhs