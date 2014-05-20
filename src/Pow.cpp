class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) return 1;
        double result = pow(x, n / 2);
        if (n < 0 && n % 2 == 0) {
            return result * result;
        } else if (n < 0 && n % 2 == -1) {
            return result * result * 1 / x;
        } else if (n > 0 && n % 2 == 0) {
            return result * result;
        } else if (n > 0 && n % 2 == 1) {
            return result * result * x;
        }
    }
};

