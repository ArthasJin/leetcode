class Solution {
public:
    string intToRoman(int num) {
        char symbols[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        string roman;
        int scale = 1000;
        for (int i = 6; i >= 0; i -= 2) {
            int digit = num / scale;
            numToRoman(digit, roman, symbols + i);
            num %= scale;
            scale /= 10;
        }
        return roman;
    }
private:
    void numToRoman(int num, string &roman, char symbols[]) {
        if (num == 0) {
            return;
        } else if (num < 4) {
            roman.append(num, symbols[0]);
        } else if (num == 4) {
            roman.append(1, symbols[0]);
            roman.append(1, symbols[1]);
        } else if (num < 9) {
            roman.append(1, symbols[1]);
            roman.append(num - 5, symbols[0]);
        } else {
            roman.append(1, symbols[0]);
            roman.append(1, symbols[2]);
        }
    }
};

