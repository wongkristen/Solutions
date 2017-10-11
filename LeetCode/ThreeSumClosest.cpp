//
// Created by Kristen Wong on 10/11/17.
//

#include <vector>
#include <cmath>

using namespace std;

class ThreeSumClosestSolution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() == 3) return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        int min = NULL;
        int ans = 0;

        for (int i = 0; i < nums.size(); i ++) {
            int mid = i + 1;
            int last = nums.size() - 1;

            while (mid < last) {
                int temp = nums[i] + nums[mid] + nums[last];
                if (temp == target) return target;
                if (abs((float) temp - target) < min || min == NULL) {
                    min = abs((float) temp - target);
                    ans = temp;
                }
                if (temp < target) mid ++;
                else last --;
            }
            while (nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};