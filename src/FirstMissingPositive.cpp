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

// updated
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        unordered_set<int> dict;
        for (int i = 0; i < n; ++i) {
            dict.insert(A[i]);
        }
        for (int i = 1; i < n + 1; ++i) {
            if (dict.find(i) == dict.end()) {
                return i;
            }
        }
        return n + 1;
    }
};

