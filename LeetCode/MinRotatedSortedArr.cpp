//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
using namespace std;

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.

class FindMinRotatedSortedArrSolution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();

        for(int i = 0; i < (length - 1); i++){
            if(nums[i] > nums[i + 1]) {return nums[i + 1];}
        }
        return nums[0];
    }
};