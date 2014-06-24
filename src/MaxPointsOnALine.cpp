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
        if (points.size() > 0) {
            int maxNum = 0;
            unordered_map<double, int> slope;
            for (int i = 0; i < points.size(); ++i) {
                slope.clear();
                int samePoint = 1;
                for (int j = i + 1; j < points.size(); ++j) {
                    if (isSame(points[i], points[j])) {
                        samePoint++;
                    } else {
                        double s = getSlope(points[i], points[j]);
                        slope[s] += 1;
                    }
                }
                maxNum = max(maxNum, samePoint);
                for (unordered_map<double, int>::iterator iter = slope.begin(); iter != slope.end(); ++iter) {
                    maxNum = max(maxNum, samePoint + iter->second);
                }
            }
            return maxNum;
        }
        return 0;
    }
private:
    bool isSame(Point &p1, Point &p2) {
        return p1.x == p2.x && p1.y == p2.y;
    }
    double getSlope(Point &p1, Point &p2) {
        if (p1.x == p2.x) {
            return INT_MAX;
        }
        return (double) (p2.y - p1.y) / (double) (p2.x - p1.x);
    }
};

