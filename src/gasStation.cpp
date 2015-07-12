/*
 *There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
 * */
#include "header.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        if (n == 0) { return -1; }
        int start = n;
        int end = n;
        int sum = 0;
        while (n-- > 0) {
            if (sum + gas[end % gas.size()] - cost[end % cost.size()] >= 0) {
                sum += (gas[end % gas.size()] - cost[end % cost.size()]);
                end++;
            } else {
                start--;
                sum += (gas[start % gas.size()] - cost[start % cost.size()]);
            }
        }
        return sum < 0 ? -1 : start % gas.size();
    }
};

int main(int argc, char **argv) {
    vector<vector<int> > grid = read_grid<int>();
    Solution s;
    cout << s.canCompleteCircuit(grid[0], grid[1]) << endl;
    return 0;
}
