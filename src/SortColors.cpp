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

