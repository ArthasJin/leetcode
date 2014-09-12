class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        do {
            res.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return res;
    }
};

// alternative
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        permute(num, 0);
        return res;
    }
private:
    vector<vector<int> > res;
    void permute(vector<int> &num, int index) {
        if (index == num.size()) {
            res.push_back(num);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            swap(num[i], num[index]);
            permute(num, index + 1);
            swap(num[i], num[index]);
        }
    }
};

