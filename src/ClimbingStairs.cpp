class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        int fn_1 = 1;
        int fn_2 = 1;
        int fn = fn_1 + fn_2;
        for (int i = 1; i < n; ++i) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

