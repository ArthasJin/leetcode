class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.length() > 0) {
            vector<string> path;
            partition(s, 0, path);
        }
        return res;
    }
private:
    vector<vector<string> > res;
    bool isPalindrome(string &s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
    void partition(string &s, int start, vector<string> &cur) {
        if (start == s.length()) {
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < s.length() - start; ++i) {
            string sub = s.substr(start, i + 1);
            if (isPalindrome(sub)) {
                cur.push_back(sub);
                partition(s, start + i + 1, cur);
                cur.pop_back();
            }
        }
    }
};

