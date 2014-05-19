class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int code = pow(2, n);
        for (int i = 0; i < code; ++i) {
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};

