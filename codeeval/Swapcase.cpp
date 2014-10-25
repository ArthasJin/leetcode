#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char swapCase(int ch) {
    if (ch >= 'a' && ch <= 'z') {
        return 'A' + ch - 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
        return 'a' + ch - 'A';
    }
    return ch;
}

int main(int argc, char **argv) {
    if (argc > 0) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            if (lineBuffer.length() > 0) {
                transform(lineBuffer.begin(), lineBuffer.end(), lineBuffer.begin(), swapCase);
                cout << lineBuffer << endl;
            }
        }
    }
    return 0;
}

