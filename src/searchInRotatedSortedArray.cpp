/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
#include "header.h"

static int find_pivot(int *a, int l, int u) {
    if (l == u) {
        return a[0] > a[l] ? l : l + 1;
    }
    if (a[(l + u) / 2] < a[0]) {
        return find_pivot(a, l, (l + u) / 2);
    } else {
        return find_pivot(a, (l + u) / 2 + 1, u);
    }
}

static int bsearch(int *a, int l, int u, int target) {
    if (l > u) {
        return -1;
    }
    if (a[(l + u) / 2] < target) {
        return bsearch(a, (l + u) / 2 + 1, u, target);
    } else if (a[(l + u) / 2] > target) {
        return bsearch(a, l, (l + u) / 2 - 1, target);
    } else {
        return (l + u) / 2;
    }
}

static int local_search(int *A, int n, int target) {
    int pivot = find_pivot(A, 0, n - 1);
    int index = bsearch(A, 0, pivot - 1, target);
    if (index == -1) {
        index = bsearch(A, pivot, n - 1, target);
    }
    return index;
}

class Solution {
public:
    int search(int A[], int n, int target) {
        return local_search(A, n, target);
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc - 1; i++) {
        v.push_back(atoi(argv[i]));
    }
    cout << local_search(&v[0], v.size(), atoi(argv[argc - 1])) << endl;
    return 0;
}