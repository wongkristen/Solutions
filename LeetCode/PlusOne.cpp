//
// Created by Kristen Wong on 10/12/17.
//

#include <iostream>
#include <vector>
using namespace std;

class PlusOneSolution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;

        while (i >= 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
                i --;
            }
            else {
                digits[i] ++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};