class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> selected(candidates.size());
        combine(candidates, 0, target, selected);
        return res;
    }
private:
    vector<vector<int> > res;
    void combine(vector<int> &candidates, int index, int target, vector<int> &selected) {
        if (index == candidates.size()) {
            if (target == 0) {
                vector<int> entry;
                for (int i = 0; i < selected.size(); ++i) {
                    for (int j = 0; j < selected[i]; ++j) {
                        entry.push_back(candidates[i]);
                    }
                }
                res.push_back(entry);
            }
            return;
        }
        int num = target / candidates[index];
        for (int i = 0; i < num + 1; ++i) {
            selected[index] = i;
            combine(candidates, index + 1, target - candidates[index] * i, selected);
        }
    }
};

