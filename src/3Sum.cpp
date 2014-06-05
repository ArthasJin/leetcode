class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        set<vector<int> > s;
        if (num.size() > 2) {
            sort(num.begin(), num.end());
            for (int i = 0; i < num.size() - 2; ++i) {
                while(i> 0 && i < num.size() - 2 && num[i] == num[i - 1]) {
                    i++;
                }
                if (num.size() - i < 3) {
                    break;
                }
                int low = i + 1, high = num.size() - 1;
                while(low < high) {
                    int sum = num[i] + num[low] + num[high];
                    if (sum > 0) {
                        high--;
                    } else if (sum < 0) {
                        low++;
                    } else {
                        vector<int> entry;
                        entry.push_back(num[i]);
                        entry.push_back(num[low]);
                        entry.push_back(num[high]);
                        s.insert(entry);
                        low++;
                        high--;
                    }
                }
            }
        }
        vector<vector<int> > res;
        res.assign(s.begin(), s.end());
        return res;
    }
};

