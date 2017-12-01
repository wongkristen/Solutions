//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
#include <string>

using namespace std;

class Island {
public:
    int length, height;
    int numIslands(vector<vector<char>> grid){
        length = grid.size();

        if(length == 0) return 0;

        height = grid[0].size();
        int islandCount = 0;

        for (int i = 0; i < length; i ++){
            for (int j = 0; j < height; j++){
                if (grid[i][j] == '1'){
                    islandCount ++;
                }
            }
        }
    }

    void markIslands(vector<vector<int>> grid, int i, int j){
        if (grid[i][j] == 0 || i < length || j < height) return;

        grid[i][j] = 0;
        markIslands(grid, i + 1, j);
        markIslands(grid, i - 1, j);
        markIslands(grid, i, j + 1);
        markIslands(grid, i, j - 1);
    }

    int garden(vector<int>&P, int &K) {
        vector<int> garden(P.size(), 0);
        for (int i = 0; i < P.size(); i ++) {
            garden[P[i]] = 0;
            int count = 0;

            for (int j = 0; j < garden.size(); j++) {
                if (garden[j] == 0) count ++;
                if (count == K) return i;
            }
        }
        return -1;
    }

    string googleSolution (string &S) {
        vector<int> nums = {S[0] - '0', S[1] - '0', S[3] - '0', S[4] - '0'};
        int min = S[0];
        bool one = false, two = false;

//        find min value of numbers
        for(int i = 1; i < nums.size(); i++){
            if (nums[i] < min) min = nums[i];
            if (nums[i] == 1) one = true;
            if (nums[i] == 2) two = true;
        }

        vector<int> ans = nums;
        for (int i = nums.size() - 1; i > 0; i--) {
            for (int j = 0; j < nums.size(); j++) {
                if(nums[j] > nums[i]) {
                    ans[i] = nums[j];

                    S = to_string(ans[0] + ans[1]) + ':' + to_string(ans[2] + ans[3]);
                    return S;
                }
            }
            ans[i] = min;
        }
        if (nums[0] == 0){
            if (one) nums[0] = 1;
            if (two) nums[0] = 2;
        }
        S = to_string(ans[0] + ans[1]) + ':' + to_string(ans[2] + ans[3]);
        return S;
    }


};