class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() > 0) {
            int start = 0, end = s.length() - 1;
            bool res = true;
            while(start < end) {
                if (isalnum(s[start]) && isalnum(s[end])) {
                    if (tolower(s[start]) == tolower(s[end])) {
                        start++, end--;
                    } else {
                        res = false;
                        break;
                    }
                } else if (!isalnum(s[start]) && isalnum(s[end])) {
                    start++;
                } else if (isalnum(s[start]) && !isalnum(s[end])) {
                    end--;
                } else if (!isalnum(s[start]) && !isalnum(s[end])) {
                    start++, end--;
                }
            }
            return res;
        }
        return true;
    }
};

