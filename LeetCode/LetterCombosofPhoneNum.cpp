//
// Created by Kristen Wong on 10/10/17.
//

#include <iostream>
#include <vector>

using namespace std;

class LetterCombosofPhoneNumSolution {
public:
    vector<string> letterCombinations(string digits) {
        vector <string> ans;
        if(digits == "") return ans;

        string letters[] = {"0", "1",
                            "abc", "def", "ghi",
                            "jkl", "mno", "pqrs",
                            "tuv", "wxyz"};
        ans.push_back("");
        for (int i = 0; i < digits.length(); i++) {
            int num = digits[i] - '0';  // convert the number character to an int
            vector <string> tempV;

            for (int j = 0; j < letters[num].length(); j++) {
                string temp = "";
                temp += letters[num][j];
                for (int k = 0 ; k < ans.size(); k++) tempV.push_back(ans[k] + temp);
            }
            ans = tempV;
        }
        return ans;
    }
};