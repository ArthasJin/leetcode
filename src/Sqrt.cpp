// binary search
class Solution {
public:
    int sqrt(int x) {
        if (x == 0) {
            return 0;
        }
        if (x == 1) {
            return 1;
        }
        long long low = 0, high = x;
        while(low + 1 < high) {
            long long mid = (low + high) / 2;
            if (mid * mid < x) {
                low = mid;
            } else if (mid * mid > x) {
                high = mid;
            } else {
                return mid;
            }
        }
        return low;
    }
};

// Newton-Raphson method
class Solution {
public:
    int sqrt(int x) {
        if (x < 0) return -1;
        double x0 = 1;
        double x1;
        while(1) {
            x1 = (x0 + x / x0) / 2;
            if (abs(x1 - x0) < 1) {
                return x1;
            }
            x0 = x1;
        }
    }
};

