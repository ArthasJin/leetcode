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

