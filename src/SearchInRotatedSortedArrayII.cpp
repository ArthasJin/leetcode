class Solution {
public:
    bool search(int A[], int n, int target) {
        map<int, int> dict;
        for (int i = 0; i < n; ++i) {
            dict[A[i]] = i;
        }
        return dict.find(target) != dict.end();
    }
};

// space O(1)
class Solution {
public:
    bool search(int A[], int n, int target) {
        if (A) {
            int low = 0, high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] == target) {
                    return true;
                } else if (A[mid] > A[low]) {
                    if (target >= A[low] && target < A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else if (A[mid] < A[low]) {
                    if (target > A[mid] && target <= A[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else {
                    low++;
                }
            }
        }
        return false;
    }
};

