//
// Created by Kristen Wong on 11/9/17.
//

#include <iostream>
#include <vector>
using namespace std;

class SubsetsSolution {
public:
    vector<vector<int>> ans = {{}};
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return ans;

        for (int i = 0; i < nums.size(); i ++) {
            vector<int> temp = {nums[i]};
            ans.push_back(temp);
            createCombo(nums, temp, i + 1);
        }
        return ans;
    }

    void createCombo(vector<int> nums, vector<int> temp, int index) {
        if (index >= nums.size()) return;
        createCombo(nums, temp, index + 1);
        temp.push_back(nums[index]);
        ans.push_back(temp);
        createCombo(nums, temp, index + 1);
    }
};
