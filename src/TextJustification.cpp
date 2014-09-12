class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        const int n = words.size();
        int begin = 0, len = 0;
        for (int i = 0; i < n; ++i) {
            if (len + words[i].size() + (i - begin) > L) {
                result.push_back(connect(words, begin, i - 1, len, L, false));
                begin = i;
                len = 0;
            }
            len += words[i].size();
        }
        result.push_back(connect(words, begin, n - 1, len, L, true));
        return result;
    }
private:
    string connect(vector<string> &words, int begin, int end, int len, int L, bool is_last) {
        string s;
        int n = end - begin + 1;
        for (int i = 0; i < n; ++i) {
            s += words[begin + i];
            addSpaces(s, i, n - 1, L - len, is_last);
        }
        if (s.size() < L) s.append(L - s.size(), ' ');
        return s;
    }
    void addSpaces(string &s, int i, int n, int L, bool is_last) {
        if (n < 1 || i > n - 1) return;
        int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
        s.append(spaces, ' ');
    }
};

// alternative
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string>res;
        int len = words.size(), i = 0;
        while(i < len) {
            int rowlen = 0, j = i;
            while(j < len && rowlen + words[j].size() <= L)
                rowlen += (words[j++].size() + 1);
            //j-i是该行放入单词的数目
            if(j - i == 1) {//处理放入一个单词的特殊情况
                res.push_back(words[i]);
                addSpace(res.back(), L - words[i].size());
                i = j;
                continue;
            }
            //charaLen是当前行字母总长度
            int charaLen = rowlen - (j - i);
            //平均每个单词后的空格,j < len 表示不是最后一行
            int meanSpace = j < len ? (L - charaLen) / (j - i - 1) : 1;
            //多余的空格
            int leftSpace = j < len ? (L - charaLen) % (j - i - 1) : L - charaLen - (j - i -1);
            string tmp;
            for(int k = i; k < j - 1; k++) {
                tmp += words[k];
                addSpace(tmp, meanSpace);
                if(j < len && leftSpace > 0) {
                    tmp.push_back(' ');
                    leftSpace--;
                }
            }
            tmp += words[j - 1];//放入最后一个单词
            if(leftSpace > 0) {
                addSpace(tmp, leftSpace); //对最后一行
            }
            res.push_back(tmp);
            i = j;
        }
        return res;
    }
private:
    void addSpace(string &s, int count) {
        for(int i = 1; i <= count; i++) {
            s.push_back(' ');
        }
    }
};

