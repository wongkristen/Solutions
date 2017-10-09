//
// Created by Kristen Wong on 10/9/17.
//

// !!!!!! NOT DONE !!!!!!
// !!!!!! NOT DONE !!!!!!
// !!!!!! NOT DONE !!!!!!
// !!!!!! NOT DONE !!!!!!

#include <iostream>
using namespace std;

class LengthofLongestSubstringSolution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        string ans;
        bool add = true;
        int longest = 0;

        if(length == 1){
            return 1;
        }
        for (int i = 0; i < length; i ++){
            for(int j = 0; j < ans.length(); j ++){
                if(ans[j] == s[i]){
                    add = false;
                    if(longest < ans.length()){
                        longest = ans.length();
                    }
                    ans = s[i];
                    break;
                }
                add = true;
            }
            if (add){
                ans += s[i];
            }
        }

        if(longest < ans.length()){
            longest = ans.length();
        }

        return longest;
    }
};