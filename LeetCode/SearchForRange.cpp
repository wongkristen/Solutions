//
// Created by Kristen Wong on 11/8/17.
//

#include <iostream>
#include <vector>
using namespace std;

class SearchForRangeSolution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        if (nums.size() == 1) {
            if(nums[0] == target) return {0, 0};
            else return {-1, -1};
        }
        int targetIndex = binarySearch(nums, target, 0, nums.size() - 1);
        if (targetIndex == -1) return {-1, -1};

        int last = targetIndex;
        while(nums[last] == target && last <= nums.size() - 1) last ++;
        last --;

        while(nums[targetIndex] == target && targetIndex >= 0) targetIndex --;
        targetIndex ++;

        return {targetIndex, last};


    }

    int binarySearch(vector<int>&arr, int target, int first, int last){
        if(first > last) return -1;
        int mid = (first + last) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] > target) return binarySearch(arr, target, first, mid - 1);
        else return binarySearch(arr, target, mid + 1, last);
    }
};
