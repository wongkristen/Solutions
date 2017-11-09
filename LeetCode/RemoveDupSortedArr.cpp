//
// Created by Kristen Wong on 11/8/17.
//

#include <iostream>
#include <vector>
using namespace std;

class RemoveDupSortedArrSolution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i ++){
            while(nums[i] == nums[i - 1] && i < nums.size()) nums.erase(nums.begin() + i);
        }
        return nums.size();
    }
};
