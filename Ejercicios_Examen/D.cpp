#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int start, end;
};

bool compareSegments(const Segment& s1, const Segment& s2) {
    return s1.start < s2.start;
}

vector<Segment> minimalCoverage(vector<Segment>& segments) {
    vector<Segment> result;
    int n = segments.size();

    sort(segments.begin(), segments.end(), compareSegments);

    int currentEnd = segments[0].end;
    result.push_back(segments[0]);

    for (int i = 1; i < n; i++) {
        if (segments[i].start > currentEnd) {
            break;
        }

        if (segments[i].end <= currentEnd) {
            continue;
        }

        result.push_back(segments[i]);
        currentEnd = segments[i].end;
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> m;

        vector<Segment> segments(m);
        for (int i = 0; i < m; i++) {
            cin >> segments[i].start >> segments[i].end;
        }

        vector<Segment> result = minimalCoverage(segments);

        if (result.empty()) {
            cout << "0\n";
        } else {
            cout << result.size() << "\n";
            for (const Segment& segment : result) {
                cout << segment.start << " " << segment.end << "\n";
            }
        }

        if (t > 0) {
            cout << "\n";
        }
    }

    return 0;
}
