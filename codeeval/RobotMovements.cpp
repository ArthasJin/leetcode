#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > res(4, vector<int>(4, 1));
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            res[i][j] = res[i - 1][j] + res[i][j - 1];
        }
    }
    cout << res[3][3] << endl;
    return 0;
}

