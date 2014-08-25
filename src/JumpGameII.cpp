class Solution {
public:
    int jump(int A[], int n) {
        if (n > 1) {
            int start = 0, end = 0, step = 0;
            while(end < n) {
                int index = 0;
                step++;
                for (int i = start; i < end + 1; ++i) {
                    if (A[i] + i > index) {
                        index = A[i] + i;
                        start = i + 1;
                    }
                    if (index >= n - 1) {
                        return step;
                    }
                }
                end = index;
            }
        }
        return 0;
    }
};

// alternative
class Solution {
public:
    int jump(int A[], int n) {
        if (A) {
            int i = n - 1;
            int step = 0;
            while (i > 0) {
                for (int j = 0; j < i; ++j) {
                    if (A[j] + j >= i) {
                        i = j;
                        step++;
                        break;
                    }
                }
            }
            return step;
        }
        return -1;
    }
};

