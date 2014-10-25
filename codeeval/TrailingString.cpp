#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int trailString(string &a, string &b) {
    int index = a.rfind(b);
    if (index == -1) {
        return 0;
    }
    return index + b.length() == a.length();
}

int main(int argc, char **argv) {
    if (argc > 1) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            if (lineBuffer.length() > 0) {
                string a = string(strtok(&lineBuffer[0], ","));
                string b = string(strtok(nullptr, ","));
                cout << trailString(a, b) << endl;
            }
        }
    }
    return 0;
}

