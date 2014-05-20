class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> sub;
        subset(S, 0, sub);
        return res;
    }
private:
    vector<vector<int> > res;
    void subset(vector<int> &S, int index, vector<int> &sub) {
        if (index == S.size()) {
            res.push_back(sub);
            return;
        }
        sub.push_back(S[index]);
        subset(S, index + 1, sub);
        sub.pop_back();
        subset(S, index + 1, sub);
    }
};

