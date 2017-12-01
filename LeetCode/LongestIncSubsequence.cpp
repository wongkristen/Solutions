//
// Created by Kristen Wong on 11/9/17.
//

#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(nlogn) - using binary search

class LongestIncSubsequenceSolution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> smallest = {nums[0]};
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == smallest[0] || nums[i] == smallest[smallest.size() - 1]) continue;
            if (nums[i] <= smallest[0]) smallest[0] = nums[i];
            else if (nums[i] > smallest[smallest.size() - 1]) smallest.push_back(nums[i]);
            else {
                int start = 0, end = smallest.size() - 1;
                while (start <= end) {
                    int mid = (start + end) / 2;
                    if (smallest[mid] == nums[i]) break;
                    if (smallest[mid] > nums[i]) {
                        if (smallest[mid - 1] < nums[i]) {
                            smallest[mid] = nums[i];
                            break;
                        } else end = mid - 1;
                    } else start = mid + 1;
                }
            }
        }

        return smallest.size();
    }
};