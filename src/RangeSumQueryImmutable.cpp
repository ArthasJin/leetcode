class NumArray {
private:
    vector<int> mNums;
public:
    NumArray(vector<int> &nums) {
        mNums.resize(nums.size() + 1);
        partial_sum(nums.begin(), nums.end(), mNums.begin() + 1);
    }

    int sumRange(int i, int j) {
        if (i >= 0 && j < mNums.size()) {
            return mNums[j + 1] - mNums[i];
        }
        return -1;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
