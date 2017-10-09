//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
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
};