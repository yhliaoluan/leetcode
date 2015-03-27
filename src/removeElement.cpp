/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (n == 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        while (right < n) {
            if (A[right] == elem) {
                right++;
            } else {
                A[left] = A[right];
                left++;
                right++;
            }
        }
        return left;
    }
};

int main(int argc, char **argv) {
    int *a = new int[argc - 2];
    for (int i = 1; i < argc - 1; i++) {
        a[i - 1] = atoi(argv[i]);
    }
    Solution s;
    int n = s.removeElement(a, argc - 2, atoi(argv[argc - 1]));
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}