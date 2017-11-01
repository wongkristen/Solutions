//
// Created by Kristen Wong on 10/19/17.
//

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(n)
// Space complexity: constant

class MoveZeroesSolution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {

            if (nums[i] == 0) {
                int j = i + 1;

                while (nums[j] == 0 && j < nums.size()) j++;
                if (j >= nums.size()) return;
                swap(nums[i], nums[j]);
            }
            i++;
        }
    }
};