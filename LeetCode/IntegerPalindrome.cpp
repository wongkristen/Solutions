//
// Created by Kristen Wong on 10/9/17.
//


//Determine whether an integer is a palindrome.

class IsPalindromeSolution {
public:
    bool isPalindrome(int x) {
        int check = 0, temp = x;
        while (x != 0) {
            check = check * 10;
            check += x % 10;
            x = x / 10;
        }
        return temp == check;
    }
};
