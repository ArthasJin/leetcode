class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return res;
    }
};

//alternative
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        permute(num, 0);
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
private:
    set<vector<int> > s;
    void permute(vector<int> &num, int index) {
        if (index == num.size()) {
            s.insert(num);
        }
        for (int i = index; i < num.size(); ++i) {
            swap(num[index], num[i]);
            permute(num, index + 1);
            swap(num[index], num[i]);
        }
    }
};

