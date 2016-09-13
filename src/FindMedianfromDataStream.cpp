class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        minHeap.push(num);
        if (minHeap.size() - maxHeap.size() > 1) {
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
        if (maxHeap.size() > 0 && maxHeap.top() > minHeap.top()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minHeap.size() - maxHeap.size() == 1) {
            return minHeap.top();
        }
        return (double) (minHeap.top() + maxHeap.top()) / 2;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

