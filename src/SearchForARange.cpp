class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res = {-1, -1};
        if (A) {
            int low = 0, high = n - 1;
            int mid = 0;
            while(low <= high) {
                mid = (low + high) / 2;
                if (A[mid] < target) {
                    low = mid + 1;
                } else if (A[mid] > target) {
                    high = mid - 1;
                } else {
                    int index = mid;
                    while(index - 1 >= 0 && A[mid] == A[index - 1]) --index;
                    res[0] = index;
                    index = mid;
                    while(index + 1 < n && A[mid] == A[index + 1]) ++index;
                    res[1] = index;
                    break;
                }
            }
        }
        return res;
    }
};

