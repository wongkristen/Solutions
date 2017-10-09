//
// Created by Kristen Wong on 10/9/17.
//

#include <iostream>
#include <vector>
using namespace std;

class LongestCommonPrefixSolution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        if (strs.size() == 0) return "";
        string ans = "";
        int index = 0;
        while (index <= strs[0].length()){
            for (int i = 1; i < strs.size(); i ++){
                for(int j = 0; j <= index; j++){
                    if(strs[0][j] != strs[i][j]) return ans;
                }
            }
            ans += strs[0][index];
            index ++;
        }
        return ans;
    }
};