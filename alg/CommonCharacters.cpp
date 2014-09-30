#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int commonCharacters(vector<string> &strs) {
    if (strs.size() == 0 || strs.size() == 1) {
        return 0;
    }
    int dict[255] = { 0 };
    int charSet[255] = { 0 };
    int res = 0;
    for (int i = 0; i < strs[0].length(); ++i) {
        dict[strs[0][i]] += 1;
    }
    for (int i = 1; i < strs.size(); ++i) {
        for (int j = 0; j < strs[i].length(); ++j) {
            if (dict[strs[i][j]] > 0) {
                charSet[strs[i][j]] += 1;
            }
        }
    }
    for (int i = 0; i < 256; ++i) {
        if (charSet[i] == strs.size()) {
            res++;
        }
    }
    return res;
}

int main() {
    vector<string> strs;
    strs.push_back("aghkafgklt");
    strs.push_back("dfghako");
    strs.push_back("qwemnaarkf");
    cout << commonCharacters(strs) << endl;
    return 0;
}

