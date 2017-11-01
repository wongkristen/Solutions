//
// Created by Kristen Wong on 10/23/17.
//

#include <iostream>
using namespace std;

// notes: the longest (length) that the answer can ever be is the length of the first number + the length of the second
// string to char: - '0'
// int to char: + '0'




class MultiplyStringsSolution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        for (int i = 0; i <= num1.size() + num2.size() - 1; i++) ans += "0";

        for (int i = num1.size() - 1; i >= 0; i --) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int prod = (ans[i + j + 1] - '0') + carry + ((num1[i] - '0') * (num2[j] - '0'));
                ans[i + j + 1] = (prod % 10) + '0';
                carry = prod / 10;
            }
            ans[i] += carry;
        }

        int i = 0;
        while (ans[i] == '0' && i < ans.size() - 1) i++;

        return i == 0 ? ans : ans.substr(i);
    }
};