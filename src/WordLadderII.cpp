class Solution {
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        queue<string> q1, q2;
        q1.push(start);
        while(!q1.empty()) {
            while(!q1.empty()) {
                string node = q1.front();
                q1.pop();
                if (node == end) {
                    path.push_back(start);
                    buildPath(start, end);
                    return res;
                }
                vector<string> level = findPath(node, dict);
                if (level.size() > 0) {
                    mp[node] = level;
                }
                for (vector<string>::iterator iter = level.begin(); iter != level.end(); ++iter) {
                    if (visited.find(*iter) == visited.end()) {
                        q2.push(*iter);
                    }
                }
            }
            swap(q1, q2);
        }
        return res;
    }
private:
    unordered_set<string> visited;
    unordered_map<string, vector<string> > mp;
    vector<vector<string> > res;
    vector<string> path;

    vector<string> findPath(string &node, unordered_set<string> &dict) {
        vector<string> res;
        visited.insert(node);
        for (int i = 0; i < node.length(); ++i) {
            string str = node;
            for (int j = 0; j < 26; ++j) {
                str[i] = j + 'a';
                if (str != node && visited.find(str) == visited.end() && dict.find(str) != dict.end()) {
                    res.push_back(str);
                }
            }
        }
        return res;
    }
    void buildPath(string &start, string &end) {
        if (start == end) {
            res.push_back(path);
        } else {
            for (int i = 0; i < mp[start].size(); ++i) {
                path.push_back(mp[start][i]);
                buildPath(mp[start][i], end);
                path.pop_back();
            }
        }
    }
};

