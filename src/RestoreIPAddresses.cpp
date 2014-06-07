class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() > 3 && s.length() < 13) {
            string ip;
            restore(s, 0, ip, 0);
        }
        return res;
    }
private:
    vector<string> res;
    bool isValid(string &ip) {
        if (ip.length() == 1) {
            return ip[0] >= '0' && ip[0] <= '9';
        } else if (ip.length() == 2) {
            return ip[0] >= '1' && ip[0] <= '9';
        } else if (ip.length() == 3) {
            int n = atoi(&ip[0]);
            return ip[0] >= '1' && ip[0] <= '2' && n >= 100 && n <= 255;
        }
        return false;
    }
    void restore(string &s, int index, string &ip, int seg) {
        if (seg == 4) {
            if (index == s.length()) {
                res.push_back(ip.substr(0, ip.length() - 1));
            }
            return;
        }
        string pre = ip;
        for (int i = 0; i < 3 && i + index < s.length(); ++i) {
            if (s.length() - index > (4 - seg) * 3) {
                return;
            }
            string sub = s.substr(index, i + 1);
            if (isValid(sub)) {
                ip += sub + ".";
                restore(s, index + i + 1, ip, seg + 1);
                ip = pre;
            }
        }
    }
};

