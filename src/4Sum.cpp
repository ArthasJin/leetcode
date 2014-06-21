class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        set<vector<int> > s;
        if (num.size() > 2) {
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size() - 3; ++i) {
                for (int j = i + 1; j < num.size() - 2; ++j) {
                    int low = j + 1;
                    int high = num.size() - 1;
                    while(low < high) {
                        int sum = num[i] + num[j] + num[low] + num[high];
                        if (sum > target) {
                            high--;
                        } else if (sum < target) {
                            low++;
                        } else {
                            vector<int> path;
                            path.push_back(num[i]);
                            path.push_back(num[j]);
                            path.push_back(num[low]);
                            path.push_back(num[high]);
                            s.insert(path);
                            low++, high--;
                        }
                    }
                }
            }
        }
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
};

