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

// more elegant solution
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n & 0x01) {
            double p = pow(x, n / 2);
            if (n > 0) {
                return p * p * x;
            } else {
                return p * p * 1 / x;
            }
        }
        double p = pow(x, n / 2);
        return p * p;
    }
};

