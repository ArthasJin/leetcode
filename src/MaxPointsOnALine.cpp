/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() == 0) {
            return 0;
        }
        if (points.size() == 1) {
            return 1;
        }
        int res = 0;
        unordered_map<double, int> m;
        for (int i = 0; i < points.size(); ++i) {
            m.clear();
            double slope;
            int same = 1;
            for (int j = i + 1; j < points.size(); ++j) {
                if (isSame(points[i], points[j])) {
                    same++;
                    continue;
                } else {
                    slope = getSlope(points[i], points[j]);
                    if (m.find(slope) != m.end()) {
                        m[slope]++;
                    } else {
                        m[slope] = 1;
                    }
                }
            }
            res = max(same, res);
            for (unordered_map<double, int>::iterator iter = m.begin(); iter != m.end(); ++iter) {
                res = max(iter->second + same, res);
            }
        }
        return res;
    }
private:
    bool isSame(Point& p1, Point& p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    double getSlope(Point& p1, Point& p2) {
        if (p1.x == p2.x) {
            return INT_MAX;
        }
        return (double) (p2.y - p1.y) / (double) (p2.x - p1.x);
    }
};

