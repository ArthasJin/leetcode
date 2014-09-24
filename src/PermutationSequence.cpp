class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact = { 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
        string res;
        for (int i = 0; i < n; ++i) {
            res.push_back(i + 1 + '0');
        }
        k--;
        for (int i = 0; i < n; ++i) {
            int m = k / fact[n - i - 1];
            int s = k % fact[n - i - 1];
            if (m == 0 && n == 0) {
                return res;
            } else {
                if (m > 0) {
                    for (int j = i + m - 1; j > i - 1; --j) {
                        swap(res[j], res[j - 1]);
                    }
                    if (s == 0) {
                        return res;
                    }
                }
            }
            k = s;
        }
        return res;
    }
};

// alternative
class Solution {
public:
    string getPermutation(int n, int k) {
        string res, candidate;
        for (int i = 1; i < n + 1; ++i) {
            candidate.push_back(i + '0');
        }
        int total = factorial(n);
        for (int i = 0; i < n; ++i) {
            total /= (n - i);
            int index = (k - 1) / total;
            res.push_back(candidate[index]);
            candidate.erase(index, 1);
            k -= index * total;
        }
        return res;
    }
private:
    int factorial(int n) {
        int res = 1;
        for (int i = 2; i < n + 1; ++i) {
            res *= i;
        }
        return res;
    }
};

