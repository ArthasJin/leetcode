class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q1, q2;
        q1.push(start);
        int level = 1;
        unordered_set<string> visited;
        while(!q1.empty()) {
            while(!q1.empty()) {
                string node = q1.front();
                q1.pop();
                for (int i = 0; i < node.length(); ++i) {
                    string str = node;
                    for (int j = 0; j < 26; ++j) {
                        str[i] = j + 'a';
                        if (str == end) {
                            return level + 1;
                        } else if (str != node && visited.find(str) == visited.end() && dict.find(str) != dict.end()) {
                            q2.push(str);
                            visited.insert(str);
                        }
                    }
                }
            }
            level++;
            swap(q1, q2);
        }
        return 0;
    }
};

