/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
*/
#include "header.h"

static int search_insert(int *a, int l, int u, int target) {
    if (l == u) {
        return a[l] >= target ? l : l + 1;
    }
    if (a[(l + u) / 2] < target) {
        return search_insert(a, (l + u) / 2 + 1, u, target);
    } else if (a[(l + u) / 2] > target) {
        return search_insert(a, l, (l + u) / 2, target);
    } else {
        return (l + u) / 2;
    }
}

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0) {
            return 0;
        }
        return search_insert(A, 0, n - 1, target);
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc - 1; i++) {
        v.push_back(atoi(argv[i]));
    }
    cout << search_insert(&v[0], 0, v.size() - 1, atoi(argv[argc - 1])) << endl;
    return 0;
}