/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        list<Interval> l;
        l.assign(intervals.begin(), intervals.end());
        list<Interval>::iterator iter = l.begin();
        vector<Interval> res;
        while(iter != l.end()) {
            if (newInterval.end < iter->start) {
                l.insert(iter, newInterval);
                res.assign(l.begin(), l.end());
                return res;
            } else if (newInterval.start > iter->end) {
                iter++;
                continue;
            } else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                iter = l.erase(iter);
            }
        }
        l.push_back(newInterval);
        res.assign(l.begin(), l.end());
        return res;
    }
};

// space O(1)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator iter = intervals.begin();
        while (iter != intervals.end()) {
            if (newInterval.end < iter->start) {
                intervals.insert(iter, newInterval);
                return intervals;
            } else if (newInterval.start > iter->end) {
                iter++;
            } else {
                newInterval.start = min(iter->start, newInterval.start);
                newInterval.end = max(iter->end, newInterval.end);
                intervals.erase(iter);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};

// O(n^2)
// Space O(n)
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), Solution::cmp);
        list<Interval> l;
        l.assign(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); ++i) {
            insert(l, intervals[i]);
        }
        res.assign(l.begin(), l.end());
        return res;
    }
    static bool cmp(Interval lhs, Interval rhs) {
        return lhs.start < rhs.start;
    }
private:
    void insert(list<Interval> &l, Interval interval) {
        list<Interval>::iterator iter = l.begin();
        while (iter != l.end()) {
            if (interval.end < iter->start) {
                l.insert(iter, interval);
                return;
            } else if (interval.start > iter->end) {
                iter++;
            } else {
                interval.start = min(interval.start, iter->start);
                interval.end = max(interval.end, iter->end);
                iter = l.erase(iter);
            }
        }
        l.push_back(interval);
    }
};

