#include <iostream>
#include <fstream>

using namespace std;

int sumDigit(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(int argc, char **argv) {
    if (argc > 1) {
        ifstream file(argv[1]);
        while (!file.eof()) {
            string lineBuffer;
            getline(file, lineBuffer);
            if (lineBuffer.length() > 0) {
                cout << sumDigit(atoi(&lineBuffer[0])) << endl;
            }
        }
    }
    return 0;
}

