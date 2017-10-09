//
// Created by Kristen Wong on 10/9/17.
//

#include <iostream>
using namespace std;

//Given a string s and a string t, check if s is subsequence of t.
//
//You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//
//Example 1:
//s = "abc", t = "ahbgdc"
//
//Return true.
//
//Example 2:
//s = "axc", t = "ahbgdc"
//
//Return false.

class IsSubSequenceSolution {
public:
    bool isSubsequence(string s, string t) {
        int sPos = 0;
        int tPos = 0;
        int sLength = s.length();
        int tLength = t.length();
        bool flag = true;

        while (flag){
            flag = false;
            for(int i = tPos; i < tLength; i++){
                if(s[sPos] == t[i]){
                    tPos = i + 1;
                    sPos ++;
                    flag = true;
                    break;
                }
            }
        }
        return sPos >= sLength;
    }
};
