//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>

using namespace std;

// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in
// the array which gives the sum of zero.


class ThreeSumSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector <vector <int>> ans;

        if (nums.size() < 3) return ans;

        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == nums[i - 1] && i - 1 >= 0) { continue; }

            int first = nums[i];
            int mid = i + 1;
            int last = nums.size() - 1;

            while (mid < last) {
                int twoSum = nums[mid] + nums[last];

                while (first * -1 < twoSum && mid < last) {
                    last --;
                    twoSum = nums[mid] + nums[last];
                }
                while (first * -1 > twoSum && mid < last) {
                    mid ++;
                    twoSum = nums[mid] + nums[last];
                }
                if(first * -1 == (twoSum) && mid < last) {
                    vector <int> temp;
                    temp.push_back(first);
                    temp.push_back(nums[mid]);
                    temp.push_back(nums[last]);
                    ans.push_back(temp);

                    while (nums[mid] == temp[1] && mid < last) mid ++;
                    while (nums[last] == temp[2] && mid < last) last --;
                }

            }
        }
        return ans;
    }
};