//
// Created by Kristen Wong on 10/9/17.
//

#include <cmath>
#include <iostream>
using namespace std;

class PowerOfFourSolution {
//    Returns true if number is a power of 4
public:
    bool isPowerOfFour(int num) {
        int x = 0;
        while (pow(4, x) <= num) {
            if (pow(4, x) == num) return true;
            x++;
        }
        return false;
    }

    bool isPowerOfFourNoLoop(int num) {
        float x = pow(num, 0.25);
        cout << x << endl;
        return floor(x) == ceil(x);
    }
};
