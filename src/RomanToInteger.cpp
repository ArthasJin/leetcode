class Solution {
public:
    int romanToInt(string s) {
        if (s.length() > 0) {
            int last = charToInt(s[0]);
            int num = last;
            for (int i = 1; i < s.length(); ++i) {
                int cur = charToInt(s[i]);
                if (cur > last) {
                    num += cur - 2 * last;
                } else {
                    num += cur;
                }
                last = cur;
            }
            return num;
        }
        return 0;
    }
private:
    int charToInt(char ch) {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};

