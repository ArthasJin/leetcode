#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int mod(int a, int b) {
    if (b != 0) {
        return a - a / b * b;
    }
    return a;
}

int main(int argc, char **argv) {
    if (argc > 0) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            char *token = strtok(&lineBuffer[0], ",");
            int a = atoi(token);
            token = strtok(nullptr, ",");
            int b = atoi(token);
            cout << mod(a, b) << endl;
        }
    }
    return 0;
}

