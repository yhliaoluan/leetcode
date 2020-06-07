/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
#include "header.h"

static int low_bound(int *a, int l, int u, int target) {
    if (l == u) {
        return a[l] == target ? l : -1;
    }
    if (a[(l + u) / 2] < target) {
        return low_bound(a, (l + u) / 2 + 1, u, target);
    } else {
        return low_bound(a, l, (l + u) / 2, target);
    }
}

static int upper_bound(int *a, int l, int u, int target) {
    if (l == u) {
        if (a[l] == target) {
            return l;
        } else if (l > 0 && a[l - 1] == target) {
            return l - 1;
        } else {
            return -1;
        }
    }
    if (a[(l + u) / 2] > target) {
        return upper_bound(a, l, (l + u) / 2, target);
    } else {
        return upper_bound(a, (l + u) / 2 + 1, u, target);
    }
}

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result(2, -1);
        if (n > 0) {
            result[0] = low_bound(A, 0, n - 1, target);
            result[1] = upper_bound(A, 0, n - 1, target);
        }
        return result;
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc - 1; i++) {
        v.push_back(atoi(argv[i]));
    }
    cout << "low bound: " << low_bound(&v[0], 0, argc - 3, atoi(argv[argc - 1])) << endl;
    cout << "upper bound: " << upper_bound(&v[0], 0, argc - 3, atoi(argv[argc - 1])) << endl;
    return 0;
}