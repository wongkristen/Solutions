//
// Created by Kristen Wong on 11/8/17.
//

#include <iostream>
using namespace std;

class PermutationsInAStringSolution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        int map[26] = {0};

        for (int i = 0; i < s1.length(); i ++) {
            map[(int) s1[i] - 97] ++;
            map[(int) s2[i] - 97] --;
        }

        for (int i = 0; i <= s2.length() - s1.length(); i ++) {
            if (checkForPerm(map)) return true;
            int right = i, left = i + s1.length();
            if (s2[right] != s2[left] && left < s2.length()){
                map[(int) s2[right] - 97] ++;
                map[(int) s2[left] - 97] --;
            }
        }
        return checkForPerm(map);


    }

    bool checkForPerm(int arr[]) {
        for(int i = 0; i < 26; i ++) {
            if(arr[i] != 0) return false;
        }
        return true;
    }
};