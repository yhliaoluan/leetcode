/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
#include "header.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[index--] = nums1[i--];
            } else {
                nums1[index--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[index--] = nums2[j--];
        }
    }
};

int main(int argc, char **argv) {
    vector<int> m1;
    m1.push_back(1);
    m1.push_back(2);
    m1.push_back(4);
    m1.push_back(5);
    m1.push_back(6);
    m1.push_back(0);
    vector<int> m2;
    m2.push_back(3);
    Solution s;
    s.merge(m1, 5, m2, 1);
    for (int i = 0; i < m1.size(); i++)
        cout << m1[i] << " ";
    cout << endl;
//    vector<vector<int> > grid = read_grid<int>();
//    int m = grid[0].size();
//    int n = grid[1].size();
//    grid[0].resize(m + n, 0);
//    Solution s;
//    s.merge(grid[0], m, grid[1], n);
//    for (int i = 0; i < grid[0].size(); i++) {
//        cout << grid[0][i] << " ";
//    }
//    cout << endl;
    return 0;
}