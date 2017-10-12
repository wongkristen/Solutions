//
// Created by Kristen Wong on 10/12/17.
//



class PowerSolution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        if (n < 0) {
            n *= -1;
            x = (1 / x);
        }
        return power(x, n);
    }

    double power(double x, int n) {
        if (n == 0) return 1;
        return (n % 2 == 0) ? power(x * x, n / 2) : x*power(x * x, n / 2);
    }
};