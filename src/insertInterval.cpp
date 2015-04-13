/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end >= newInterval.start) {
                int j = i;
                while (j < intervals.size()) {
                    if (intervals[j].start > newInterval.end) {
                        break;
                    } else {
                        newInterval.start = min(newInterval.start, intervals[j].start);
                        newInterval.end = max(newInterval.end, intervals[j].end);
                    }
                    j++;
                }
                intervals.erase(intervals.begin() + i, intervals.begin() + j);
                intervals.insert(intervals.begin() + i, newInterval);
                return intervals;
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};

int main(int argc, char **argv) {
    vector<Interval> intervals;
    for (int i = 1; i < argc - 2; i += 2) {
        intervals.push_back(Interval(atoi(argv[i]), atoi(argv[i + 1])));
    }
    Solution s;
    vector<Interval> result = s.insert(intervals, Interval(atoi(argv[argc - 2]), atoi(argv[argc - 1])));
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i].start << "," << result[i].end << "]";
    }
    cout << endl;
    return 0;
}