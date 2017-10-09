//
// Created by Kristen Wong on 10/9/17.
//

#include <vector>
using namespace std;

// Given numRows, generate the first numRows of Pascal's triangle.

class PascalsTriangleSolution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> outer;
        if (numRows == 0){
            return outer;
        }

        if (numRows == 1){
            return (vector<vector<int>> {{1}});
        }

        outer.push_back(vector<int> {1});

        for (int i = 1; i < numRows; i++){
            vector<int> inner;
            inner.push_back(1);
            for(int j = 1; j < i; j++){
                inner.push_back(outer[i - 1][j - 1] + outer[i - 1][j]);
            }
            inner.push_back(1);
            outer.push_back(inner);
        }
        return outer;
    }
};