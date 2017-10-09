//
// Created by Kristen Wong on 10/9/17.
//

#include <iostream>
using namespace std;

// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321

class ReverseIntegerSolution {
public:
    int reverse(int x) {
        if(x < 10 && x > -10) {return x;}

        bool neg = false;
        if (x < 0) {
            x = -x;
            neg = true;
        }

        string intString = to_string(x);
        string temp;
        for(int i = intString.length() - 1; i >= 0; i--){
            temp.push_back(intString[i]);
        }

        long num;

        num = stol(temp, nullptr, 10);
        if(neg){
            num = -num;
        }

        cout << num << endl;
        cout << INT_MAX << endl;
        if(num > INT_MAX || num < INT_MIN){
            return 0;
        }else{
            x = (int) num;
            return x;
        }
    }
};
