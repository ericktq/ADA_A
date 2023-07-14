#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double closestPairDistance(const vector<Point>& points) {
    int n = points.size();
    double minDistance = numeric_limits<double>::max();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = distance(points[i], points[j]);
            minDistance = min(minDistance, dist);
        }
    }

    return minDistance;
}

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<Point> points(n);

        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }

        double closestDistance = closestPairDistance(points);

        if (closestDistance < 10000) {
            cout << fixed << setprecision(4) << closestDistance << endl;
        } else {
            cout << "INFINITY" << endl;
        }
    }

    return 0;
}
