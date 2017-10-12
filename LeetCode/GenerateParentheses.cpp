//
// Created by Kristen Wong on 10/11/17.
//


#include <iostream>
#include <vector>

using namespace std;

class GenerateParenthesesSolution {
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        if (n == 0) return ans;
        createCombos("", 0, 0, n);
        return ans;
    }

//    open = # of parentheses that need to be closed
//    left = total # of left parentheses
    void createCombos(string parentheses, int open, int left, int n) {
        if (parentheses.length() == n * 2) {
            ans.push_back(parentheses);
            return;
        }
        if (!open) createCombos(parentheses + "(", open + 1, left + 1, n);
        else {
            createCombos(parentheses + ")", open - 1, left, n);
            if (left < n) createCombos(parentheses + "(", open + 1, left + 1, n);
        }
    }
};