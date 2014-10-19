#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isSame(int x, int a, int b) {
    int bit1 = x >> (a == 0 ? 0 : a - 1) & 0x01;
    int bit2 = x >> (b == 0 ? 0 : b - 1) & 0x01;
    return bit1 == bit2;
}

int main(int argc, char **argv) {
    ifstream file;
    file.open(argv[1]);
    string lineBuffer;
    while (!file.eof()) {
        getline(file, lineBuffer);
        if (lineBuffer.length() > 0) {
            char *token = strtok(&lineBuffer[0], ",");
            int x = atoi(token);
            token = strtok(nullptr, ",");
            int a = atoi(token);
            token = strtok(nullptr, ",");
            int b = atoi(token);
            if (isSame(x, a, b)) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }
    return 0;
}

