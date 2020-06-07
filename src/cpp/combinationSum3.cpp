/*
 *Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 * */
#include "header.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> arr;
        add(1, k, n, arr, result);
        return result;
    }

    void add(int num, int k, int n, vector<int>& arr,
        vector<vector<int>>& result) {
        if (n == 0 && k == 0) {
            result.push_back(arr);
            return;
        }
        if (n <= 0 || k <= 0 || num > 9) { return; }
        add(num + 1, k, n, arr, result);
        arr.push_back(num);
        add(num + 1, k - 1, n - num, arr, result);
        arr.pop_back();
    }
};

int main(int argc, char **argv) {
    print_grid(Solution().combinationSum3(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
