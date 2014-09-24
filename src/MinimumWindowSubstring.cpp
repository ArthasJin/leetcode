class Solution {
public:
    string minWindow(string S, string T) {
        if (T.length() == 0 && S.length() == 0) {
            return "";
        }
        if (T.length() > S.length()) {
            return "";
        }
        int expect[256] = { 0 };
        int appear[256] = { 0 };
        int start = 0, minLength = INT_MAX, count = 0, end = 0, minStart = 0;
        for (int i = 0; i < T.length(); ++i) {
            expect[T[i]]++;
        }
        for (end = 0; end < S.length(); ++end) {
            if (expect[S[end]] > 0) {
                appear[S[end]]++;
                if (expect[S[end]] >= appear[S[end]]) {
                    count++;
                }
            }
            if (count == T.length()) {
                while(expect[S[start]] == 0 || appear[S[start]] > expect[S[start]]) {
                    appear[S[start]]--;
                    start++;
                }
                if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                    minStart = start;
                }
            }
        }
        if (minLength == INT_MAX) {
            return "";
        }
        return S.substr(minStart, minLength);
    }
};

// alternative
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() == 0 || T.length() == 0 || T.length() > S.length()) {
            return "";
        }
        unordered_map<char, int> dict;
        for (int i = 0; i < T.length(); ++i) {
            dict[T[i]] += 1;
        }
        int start = 0, end = 0, count = 0, minStart = -1, minWidth = INT_MAX;
        unordered_map<char, int> curDict;
        while (end < S.length()) {
            if (dict.find(S[end]) != dict.end()) {
                curDict[S[end]] += 1;
                if (curDict[S[end]] <= dict[S[end]]) {
                    count++;
                }
            }
            if (count == T.length()) {
                while (start < end && dict.find(S[start]) == dict.end() || curDict[S[start]] > dict[S[start]]) {
                    if (dict.find(S[start]) != dict.end()) {
                        curDict[S[start]]--;
                    }
                    start++;
                }
                if (minWidth > (end - start + 1)) {
                    minWidth = end - start + 1;
                    minStart = start;
                }
            }
            end++;
        }
        if (minStart == -1) {
            return "";
        }
        return S.substr(minStart, minWidth);
    }
};

// alternative
class Solution {
public:
    string minWindow(string S, string T) {
        int dict[255] = { 0 };
        for (int i = 0; i < T.length(); ++i) {
            dict[T[i]] += 1;
        }
        int minStart = 0, minEnd = INT_MAX, start = 0, end = 0, num = 0;
        int m[255] = { 0 };
        while (end < S.length()) {
            if (dict[S[end]] > 0) {
                m[S[end]]++;
                if (m[S[end]] <= dict[S[end]]) {
                    num++;
                }
            }
            if (num == T.length()) {
                while (start < end && (m[S[start]] > dict[S[start]] || dict[S[start]] == 0)) {
                    if (dict[S[start]] > 0) {
                        m[S[start]]--;
                    }
                    start++;
                }
                if (minEnd - minStart > end - start) {
                    minStart = start;
                    minEnd = end;
                }
            }
            end++;
        }
        if (minEnd == INT_MAX) {
            return "";
        }
        return S.substr(minStart, minEnd - minStart + 1);
    }
};

