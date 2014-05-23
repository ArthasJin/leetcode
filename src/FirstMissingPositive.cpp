class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(A[i]);
        }
        for (int i = 1; i < n + 2; ++i) {
            if (s.find(i) == s.end()) {
                return i;
            }
        }
        return 1;
    }
};

