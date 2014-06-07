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
        list<Interval> l;
        sort(intervals.begin(), intervals.end(), compare);
        l.assign(intervals.begin(), intervals.end());
        list<Interval>::iterator pre = l.begin();
        list<Interval>::iterator iter = l.begin();
        iter++;
        while(iter != l.end()) {
            if (iter->start <= pre->end) {
                pre->end = max(iter->end, pre->end);
                iter = l.erase(iter);
            } else {
                pre++, iter++;
            }
        }
        res.assign(l.begin(), l.end());
        return res;
    }
private:
    static int compare(Interval i1, Interval i2) {
        return i1.start < i2.start;
    }
};

