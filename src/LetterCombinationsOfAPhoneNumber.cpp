class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> dict;
        dict['1'] = "";
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        dict['0'] = " ";
        if (digits.length() > 0) {
            vector<string> v;
            for(int i = 0; i < digits.length(); ++i) {
                v.push_back(dict[digits[i]]);
            }
            string entry;
            combine(v, 0, entry);
            return res;
        }
        res.push_back("");
        return res;
    }
private:
    vector<string> res;
    void combine(vector<string> &v, int index, string &entry) {
        if (index == v.size()) {
            res.push_back(entry);
            return;
        }
        for (int i = 0; i < v[index].size(); ++i) {
            entry.push_back(v[index][i]);
            combine(v, index + 1, entry);
            entry.pop_back();
        }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int, string> dict;
        dict[0] = " ";
        dict[1] = "";
        dict[2] = "abc";
        dict[3] = "def";
        dict[4] = "ghi";
        dict[5] = "jkl";
        dict[6] = "mno";
        dict[7] = "pqrs";
        dict[8] = "tuv";
        dict[9] = "wxyz";
        vector<string> res;
        string entry;
        combine(digits, 0, entry, dict, res);
        return res;
    }
private:
    void combine(string &digits, int index, string &entry, unordered_map<int, string> &dict, vector<string> &res) {
        if (index == digits.size()) {
            res.push_back(entry);
            return;
        }
        for (int i = 0; i < dict[digits[index] - '0'].length(); ++i) {
            entry.push_back(dict[digits[index] - '0'][i]);
            combine(digits, index + 1, entry, dict, res);
            entry.pop_back();
        }
    }
};

