class Solution {
public:
    int search(int A[], int n, int target) {
        map<int, int> dict;
        for (int i = 0; i < n; ++i) {
            dict[A[i]] = i;
        }
        if (dict.find(target) != dict.end()) {
            return dict[target];
        }
        return -1;
    }
};

