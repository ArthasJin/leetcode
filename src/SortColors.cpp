class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n - 1, i = 0;
        while(i < blue + 1) {
            if (A[i] == 0) {
                swap(A[red], A[i]);
                i++, red++;
            } else if (A[i] == 1) {
                i++;
            } else if (A[i] == 2) {
                swap(A[i], A[blue]);
                blue--;
            }
        }
    }
};

// counting sort
class Solution {
public:
    void sortColors(int A[], int n) {
        int count[3] = { 0 };
        for (int i = 0; i < n; ++i) {
            count[A[i]] += 1;
        }
        for (int i = 0; i < 3; ++i) {
            int start = 0;
            for (int j = 0; j < i; ++j) {
                start += count[j];
            }
            for (int k = 0; k < count[i]; ++k) {
                A[k + start] = i;
            }
        }
    }
};

