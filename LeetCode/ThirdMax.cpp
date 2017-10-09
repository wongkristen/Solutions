//
// Created by Kristen Wong on 10/9/17.
//

#include <iostream>
#include <vector>
using namespace std;

class ThirdMaxSolution {
public:
    int thirdMax(vector<int>& nums) {
        int max = NULL, max2 = NULL, max3 = NULL;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > max || max == NULL){
                int temp = max;
                int temp2 = max2;
                max = nums[i];
                max2 = temp;
                max3 = temp2;
                continue;
            } else if ((nums[i] > max2 && nums[i] != max) || (max2 == NULL && nums[i] != max)) {
                int temp = max2;
                max2 = nums[i];
                max3 = temp;
                continue;
            } else if ((nums[i] > max3 && (nums[i] != max && nums[i] != max2)) || (nums[i] == NULL && (nums[i] != max && nums[i] != max2))) {
                max3 = nums[i];
            }
        }
        cout << max << endl;
        cout << max3 << endl;
        if (max3 == NULL && max2 == NULL) return max;
        else if (max3 == NULL) return max;
        return max3;
    }
};