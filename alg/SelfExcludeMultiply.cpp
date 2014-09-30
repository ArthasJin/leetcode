#include <iostream>
#include <vector>

using namespace std;

vector<int> selfExcludeMultiply(vector<int> &input) {
    int zero = 0, prod = 1;
    vector<int> res(input.size());
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 0) {
            zero++;
            if (zero == 2) {
                return res;
            }
        } else {
            prod *= input[i];
        }
    }
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 0) {
            res[i] = prod;
        } else {
            res[i] = prod / input[i];
        }
    }
    return res;
}

int main() {
    vector<int> input = { 1,2,0,4,5,0,7,8 };
    vector<int> output = selfExcludeMultiply(input);
    for (auto i : output) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

