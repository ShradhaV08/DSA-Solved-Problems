double myPow(double x, int n) {
    long long exp = n;   // handle INT_MIN safely

    if (exp < 0) {
        x = 1.0 / x;
        exp = -exp;
    }

    double result = 1.0;

    while (exp > 0) {
        if (exp % 2 == 1)
            result *= x;

        x *= x;
        exp /= 2;
    }

    return result;
}