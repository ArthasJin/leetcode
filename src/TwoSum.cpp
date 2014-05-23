// Sort solution
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int> > num;
        for (int i = 0; i < numbers.size(); ++i) {
            num.push_back(make_pair(i, numbers[i]));
        }
        sort(num.begin(), num.end(), compare);
        int start = 0, end = num.size() - 1, sum = 0;
        vector<int> res;
        while(start < end) {
            sum = num[start].second + num[end].second;
            if (sum > target) {
                end--;
            } else if (sum < target) {
                start++;
            } else if (sum == target) {
                res.push_back(num[start].first + 1);
                res.push_back(num[end].first + 1);
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
private:
    static int compare(pair<int, int> p1, pair<int, int> p2) {
        return p1.second < p2.second;
    }
};

// Hash map solution
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); ++i) {
            m[numbers[i]] = i + 1;
        }
        vector<int> res;
        for (int i = 0; i < numbers.size(); ++i) {
            int index = m[target - numbers[i]];
            if (index > 0 && index != (i + 1)) {
                res.push_back(i + 1);
                res.push_back(m[target - numbers[i]]);
                break;
            }
        }
        return res;
    }
};

