//
// Created by Kristen Wong on 10/9/17.
//

#include <iostream>
using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to
// display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
//        Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class ZigZagConversionSolution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {return s;}

        int length = s.length();
        int row = 0;
        bool down = true;
        string ans[numRows];

        for (int i = 0; i < length; i++){
            ans[row].push_back(s[i]);

            if (row == (numRows - 1)){
                down = false;
            }
            else if (row == 0){
                down = true;
            }

            down ? row ++ : row --;
        }
        for(int i = 1; i < numRows; i++){
            ans[0] += ans[i];
        }

        return ans[0];

    }
};