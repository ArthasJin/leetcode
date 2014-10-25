#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (i == 0 && j > 0) {
                cout << right << setw(4) << j + 1;
            } else if (j == 0) {
                cout << right << i + 1;
            } else if (j < 12) {
                cout << right << setw(4) << (i + 1) * (j + 1);
            }
        }
        cout << endl;
    }
    return 0;
}

