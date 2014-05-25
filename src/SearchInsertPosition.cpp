class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if (mid > low && A[mid - 1] < target && A[mid] > target ) {
                return mid;
            } else if (A[mid] > target) {
                high = mid - 1;
            } else if (A[mid] < target) {
                low = mid + 1;
            } else if (A[mid] == target) {
                return mid;
            }
        }
        return low;
    }
};

