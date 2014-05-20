class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<int> sub;
        subset(S, 0, sub);
        vector<vector<int> > rt;
        rt.assign(res.begin(), res.end());
        return rt;
    }
private:
    set<vector<int> > res;
    void subset(vector<int> &S, int index, vector<int> &sub) {
        if (index == S.size()) {
            res.insert(sub);
            return;
        }
        sub.push_back(S[index]);
        subset(S, index + 1, sub);
        sub.pop_back();
        subset(S, index + 1, sub);
    }
};

