//
// Created by Kristen Wong on 10/10/17.
//

#include <iostream>
#include <stack>

using namespace std;

class ValidParenthesesSolution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;

        stack<char> open;
        for (int i = 0; i < s.length(); i ++) {
            char current = s[i];
            char temp;

            switch (current) {
                case ('{'):
                    open.push(s[i]);
                    break;

                case ('['):
                    open.push(s[i]);
                    break;

                case ('('):
                    open.push(s[i]);
                    break;

                case ('}'):
                    if (open.empty() || open.top() != '{') return false;
                    else open.pop();
                    break;

                case (']'):
                    if (open.empty() || open.top() != '[') return false;
                    else open.pop();
                    break;

                case (')'):
                    if (open.empty() || open.top() != '(') return false;
                    else open.pop();
                    break;

                default:
                    return false;
            }

        }
        return open.empty();
    }
};