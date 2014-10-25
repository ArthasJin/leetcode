#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    if (argc > 0) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            if (lineBuffer.length() > 0) {
                transform(lineBuffer.begin(), lineBuffer.end(), lineBuffer.begin(), ::tolower);
                cout << lineBuffer << endl;
            }
        }
    }
    return 0;
}

