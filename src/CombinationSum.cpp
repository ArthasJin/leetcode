class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> selected(candidates.size());
        combine(candidates, 0, target, selected);
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    set<vector<int> > s;
    void combine(vector<int> &num, int index, int target, vector<int> &selected) {
        if (index == num.size()) {
            if (target == 0) {
                vector<int> entry;
                for (int i = 0; i < selected.size(); ++i) {
                    for (int j = 0; j < selected[i]; ++j) {
                        entry.push_back(num[i]);
                    }
                }
                s.insert(entry);
            }
            return;
        }
        int n = target / num[index];
        for (int i = 0; i < n + 1; ++i) {
            selected[index] = i;
            combine(num, index + 1, target - i * num[index], selected);
        }
    }
};

