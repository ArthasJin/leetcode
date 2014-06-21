class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        height.push_back(0);
        int i = 0, area = 0;
        while(i < height.size()) {
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                area = max(area, height[t] * (stk.empty()? i : i - stk.top() - 1));
            }
        }
        return area;
    }
};

