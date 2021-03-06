class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> input;
        for (int i = 0; i < n; ++i) {
            input.push_back(i + 1);
        }
        vector<int> entry;
        combine(input, 0, k, entry);
        return res;
    }
private:
    vector<vector<int> > res;
    void combine(vector<int> &input, int index, int k, vector<int> &entry) {
        if (!entry.empty() && entry.size() == k) {
            res.push_back(entry);
            return;
        }
        for (int i = index; i < input.size(); ++i) {
            entry.push_back(input[i]);
            combine(input, i + 1, k, entry);
            entry.pop_back();
        }
    }
};

// alternative
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> entry;
        combine(n, k, 0, entry);
        return res;
    }
private:
    vector<vector<int> > res;
    void combine(int n, int k, int index, vector<int> &entry) {
        if (entry.size() == k) {
            res.push_back(entry);
            return;
        }
        for (int i = index; i < n; ++i) {
            entry.push_back(i + 1);
            combine(n, k, i + 1, entry);
            entry.pop_back();
        }
    }
};

