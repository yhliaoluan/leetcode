/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include "header.h"

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool sort_interval(const Interval &l, const Interval &r) {
    return l.start < r.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() < 2) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), sort_interval);
        vector<Interval> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            Interval &last = result[result.size() - 1];
            if (last.end < intervals[i].start) {
                result.push_back(intervals[i]);
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    int start, end;
    vector<Interval> intervals;
    while (cin >> start, cin >> end) {
        intervals.push_back(Interval(start, end));
    }
    Solution s;
    vector<Interval> result = s.merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i].start << "," << result[i].end << "] ";
    }
    cout << endl;
    return 0;
}