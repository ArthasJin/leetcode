class Solution {
public:
    bool canJump(int A[], int n) {
        int reach = 1;
        for (int i = 0; i < reach && i < n; ++i) {
            reach = max(reach, i + 1 + A[i]);
        }
        return reach >= n;
    }
};

