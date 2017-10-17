//
// Created by Kristen Wong on 10/17/17.
//

#include <vector>
#include <iostream>
using namespace std;

class SetMatrixZeroesSolution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;

        bool firstRowZero = false, firstColZero = false;
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) firstRowZero = true;
        }
        for (int i = 0; i < matrix.size(); i ++) {
            if (matrix[i][0] == 0) firstColZero = true;
            for (int j = 0; j < matrix[0].size(); j ++) {

                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        cout << endl;
        for (int j = 1; j < matrix[0].size(); j ++){
            if (matrix[0][j] == 0) {
                for (int i = 1; i < matrix.size(); i ++) matrix[i][j] = 0;
            }
        }

        for (int i = 1; i < matrix.size(); i ++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[i].size(); j ++) matrix[i][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < matrix.size(); i ++) matrix[i][0] = 0;
        }

        if (firstRowZero) {
            for (int i = 0; i < matrix[0].size(); i ++) matrix[0][i] = 0;
        }
    }
};