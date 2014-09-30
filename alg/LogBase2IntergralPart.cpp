#include <iostream>

using namespace std;

int log2(int n) {
    int res = 0;
    while (n >>= 1) {
        res++;
    }
    return res;
}

int main() {
    cout << log2(1) << endl;
    cout << log2(2) << endl;
    cout << log2(4) << endl;
    cout << log2(5) << endl;
    cout << log2(6) << endl;
    cout << log2(10) << endl;
    cout << log2(100) << endl;
    return 0;
}

