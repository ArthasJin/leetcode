#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int multiple(int a, int b) {
    if (a % b) {
        return int(a / b + 1) * b;
    }
    return a;
}

int main(int argc, char **argv) {
    ifstream file(argv[1]);
    while (!file.eof()) {
        string lineBuffer;
        getline(file, lineBuffer);
        if (lineBuffer.length() > 0) {
            int a = atoi(strtok(&lineBuffer[0], ","));
            int b = atoi(strtok(NULL, ","));
            cout << multiple(a, b) << endl;
        }
    }
    return 0;
}

