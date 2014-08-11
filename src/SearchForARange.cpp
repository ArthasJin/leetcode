// O(n) for worst case
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

// O(logn) for worst case
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        if (n > 0) {
            int low = 0, high = n;
            while(low < high) {
                int mid = (low + high) / 2;
                if (A[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            if (A[low] == target) {
                res[0] = low;
            } else {
                return res;
            }
            low = 0, high = n;
            while(low < high) {
                int mid = (low + high) / 2;
                if (A[mid] > target) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            res[1] = low - 1;
        }
        return res;
    }
};

