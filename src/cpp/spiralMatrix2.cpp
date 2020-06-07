/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
#include "header.h"

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        for (int i = 0; i < n; i++) {
            vector<int> s(n, 0);
            result.push_back(s);
        }
        int pos[2] = { 0, -1 };
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = n;
        int i = m * n; 
        int d = 0;
        int val = 1;
        while (i > 0) {
            for (int x = 0; x < n; x++) {
                i--;
                pos[0] += dir[d][0];
                pos[1] += dir[d][1];
                result[pos[0]][pos[1]] = val++;
            }
            m--;
            swap(m, n);
            d = (d + 1) % 4;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<vector<int> > result = s.generateMatrix(atoi(argv[1]));
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}