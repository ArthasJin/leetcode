#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
    if (argc > 1) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            if (lineBuffer.length() > 0) {
                vector<double> v;
                char *digit = strtok(&lineBuffer[0], " ");
                while (digit) {
                    v.push_back(atof(digit));
                    digit = strtok(nullptr, " ");
                }
                sort(v.begin(), v.end());
                for (size_t i = 0; i < v.size(); ++i) {
                    cout.precision(3);
                    cout << fixed << v[i];
                    if (i != v.size() - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}

