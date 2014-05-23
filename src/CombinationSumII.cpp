class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> entry;
        sort(num.begin(), num.end());
        combine(num, 0, target, entry);
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    set<vector<int> > s;
    void combine(vector<int> &num, int index, int target, vector<int> &entry) {
        if (target == 0 && !entry.empty()) {
            s.insert(entry);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            if (target < num[i]) return;
            entry.push_back(num[i]);
            combine(num, i + 1, target - num[i], entry);
            entry.pop_back();
        }
    }
};

