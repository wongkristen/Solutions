//
// Created by Kristen Wong on 10/24/17.
//

// Time complexity: O(n)

class ClimbingStairsSolution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;

        int x = 1;
        int y = 1;
        while (n > 0) {
            int temp = x + y;
            x = y;
            y = temp;
            n --;
        }
        return x;
    }
};