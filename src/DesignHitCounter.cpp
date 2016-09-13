class HitCounter {
private:
    deque<int> q;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        while (!q.empty() && (timestamp - q.front()) >= 300) {
            q.pop_front();
        }
        q.push_back(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int diff = timestamp - 300;
        return q.size() - (upper_bound(q.begin(), q.end(), diff) - q.begin());
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

