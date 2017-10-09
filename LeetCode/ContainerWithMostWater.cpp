//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
using namespace std;

//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines
//are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
//forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

class MaxAreaSolution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, max = 0;
        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            max = area > max ? area : max;

            int currHeight = min(height[i], height[j]);

            while (height[j] <= currHeight && i < j) j--;
            while (height[i] <= currHeight && i < j) i++;
        }
        return max;
    }
};