class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.size() > 0) {
            for (int i = 0; i < strs[0].length(); ++i) {
                bool isPrefix = true;
                for (int j = 1; j < strs.size(); ++j) {
                    if (strs[0][i] != strs[j][i]) {
                        isPrefix = false;
                        break;
                    }
                }
                if (isPrefix) {
                    prefix.push_back(strs[0][i]);
                } else {
                    break;
                }
            }
        }
        return prefix;
    }
};

