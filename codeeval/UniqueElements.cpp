#include <iostream>
#include <fstream>
#include <cstring>
#include <set>

using namespace std;

int main(int argc, char **argv) {
    if (argc > 1) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            if (lineBuffer.length() > 0) {
                set<int> s;
                char *element = strtok(&lineBuffer[0], ",");
                while (element) {
                    s.insert(atoi(element));
                    element = strtok(nullptr, ",");
                }
                int i = 0;
                for (set<int>::iterator iter = s.begin(); iter != s.end(); ++iter, ++i) {
                    cout << *iter;
                    if (i < s.size() - 1) {
                        cout << ",";
                    }
                }
                cout << endl;
            }
        }
    }
}

