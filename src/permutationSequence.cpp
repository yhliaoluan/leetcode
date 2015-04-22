/*
 The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 * */
#include "header.h"

class Solution {
public:
    string getPermutation(int n, int k) {
        int a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        k = (k - 1) % factorial(n);
        kth(a, n, k);
        string ret;
        for (int i = 0; i < n; i++)
            ret += ((char) (a[i] + '0'));
        return ret;
    }
    void kth(int *a, int n, int k) {
        if (k == 0) return;
        int i = 0;
        int fac = factorial(n - 1);
        while (k - fac >= 0) {
            k -= fac;
            i++;
        }
        int tmp = a[i];
        while (i > 0) {
            a[i] = a[i - 1];
            i--;
        }
        a[0] = tmp;
        kth(a + 1, n - 1, k);
    }
    int factorial(int n) {
        if (n == 1) return 1;
        return n * factorial(n - 1);
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.getPermutation(atoi(argv[1]), atoi(argv[2])) << endl;
    return 0;
}
