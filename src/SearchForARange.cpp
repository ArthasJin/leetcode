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

// alternative O(logn) solution
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res = {-1, -1};
        if (A) {
            res[0] = findLeft(A, 0, n - 1, target);
            res[1] = findRight(A, n, 0, n - 1, target);
        }
        return res;
    }
private:
    int findLeft(int array[], int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            if (mid > 0 && array[mid - 1] == target) {
                return findLeft(array, 0, mid - 1, target);
            } else {
                return mid;
            }
        } else if (array[mid] > target) {
            return findLeft(array, left, mid - 1, target);
        } else {
            return findLeft(array, mid + 1, right, target);
        }
    }
    int findRight(int array[], int n, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (array[mid] == target) {
            if (mid < n - 1 && array[mid + 1] == target) {
                return findRight(array, n, mid + 1, right, target);
            } else {
                return mid;
            }
        } else if (array[mid] > target) {
            return findRight(array, n, left, mid - 1, target);
        } else {
            return findRight(array, n, mid + 1, right, target);
        }
    }
};

