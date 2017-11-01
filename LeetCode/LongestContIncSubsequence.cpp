//
// Created by Kristen Wong on 10/23/17.
//

#include <iostream>
#include <vector>
using namespace std;

class LongestContIncSubsequenceSolution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int longest = 1;
        int current = 1;
        int i = 1;

        while (i < nums.size()) {
            if (nums[i] > nums[i - 1]) current ++;
            else {
                longest = max(longest, current);
                current = 1;
            }
            i ++;
        }
        return max(longest, current);
    }
};