class Solution {
public:
    bool search(int A[], int n, int target) {
        map<int, int> dict;
        for (int i = 0; i < n; ++i) {
            dict[A[i]] = i;
        }
        return dict.find(target) != dict.end();
    }
};

