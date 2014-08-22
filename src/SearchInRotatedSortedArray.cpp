class Solution {
public:
    int search(int A[], int n, int target) {
        map<int, int> dict;
        for (int i = 0; i < n; ++i) {
            dict[A[i]] = i;
        }
        if (dict.find(target) != dict.end()) {
            return dict[target];
        }
        return -1;
    }
};

// space O(1)
class Solution {
public:
    int search(int A[], int n, int target) {
        if (A) {
            int low = 0, high = n - 1;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if (A[mid] == target) {
                    return mid;
                } else if (A[mid] >= A[low]) {
                    if (target >= A[low] && target <= A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else {
                    if (target >= A[low] || target <= A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};

