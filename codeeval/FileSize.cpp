#include <iostream>
#include <fstream>

using namespace std;

int getSize(const string &filename) {
    ifstream file(filename, ios::binary);
    streampos begin = file.tellg();
    file.seekg(0, ios::end);
    streampos end = file.tellg();
    return end - begin;
}

int main(int argc, char **argv) {
    cout << getSize(argv[1]) << endl;
    return 0;
}

