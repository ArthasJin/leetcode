#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char ** argv) {
    ifstream file(argv[1]);
    string lineBuffer;
    int sum = 0;
    while (!file.eof()) {
        getline(file, lineBuffer);
        sum += atoi(&lineBuffer[0]);
    }
    cout << sum << endl;
    return 0;
}

