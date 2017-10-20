//
// Created by Kristen Wong on 10/18/17.
//

#include <iostream>
#include <vector>
using namespace std;

// Time complexity: O(n) - where n is the length of the given vector
// Space complexity: constant

class JumpGameSolution {
public:
    bool canJump(vector<int>& nums) {
        int max = 0;
        int i = 0;
        for (i = 0; i < nums.size() && i <= max; i++) {
            int temp = i + nums[i];
            if (max < temp) max = temp;
        }
        return i == nums.size();
    }
};