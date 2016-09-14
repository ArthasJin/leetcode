class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) {
            return words.front();
        }
        unordered_map<char, unordered_set<char>> g;
        for (int i = 1; i < words.size(); i++) {
            string t1 = words[i - 1];
            string t2 = words[i];
            bool found = false;
            for (int j = 0; j < max(t1.length(), t2.length()); j++) {
                if (j < t1.length() && g.count(t1[j]) == 0)
                    g.insert(make_pair(t1[j], unordered_set<char>()));
                if (j < t2.length() && g.count(t2[j]) == 0)
                    g.insert(make_pair(t2[j], unordered_set<char>()));
                if (j < t1.length() && j < t2.length() && t1[j] != t2[j] && !found) {
                    g[t1[j]].insert(t2[j]);
                    found = true;
                }
            }
        }
        string res;
        int size = g.size();
        queue<char> q;
        for (auto it = g.begin(); it != g.end();) {
            if (it->second.empty()) {
                q.push(it->first);
                it = g.erase(it);
            } else {
                ++it;
            }
        }
        while (!q.empty()) {
            char cur = q.front();
            q.pop();
            res.append(1, cur);
            for (auto it = g.begin(); it != g.end();) {
                it->second.erase(cur);
                if (it->second.empty()) {
                    q.push(it->first);
                    it = g.erase(it);
                } else {
                    ++it;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res.length() == size ? res : "";
    }
};

