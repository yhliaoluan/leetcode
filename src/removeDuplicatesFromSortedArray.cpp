/*
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place with constant memory.

 For example,
 Given input array A = [1,1,2],

 Your function should return length = 2, and A is now [1,2]. 
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) {
            return n;
        }
        int left = 1;
        int right = 1;
        int last = A[0];
        while (right < n) {
            if (A[right] == last) {
                right++;
            } else {
                last = A[left] = A[right];
                left++;
                right++;
            }
        }
        return left;
    }
};

int main(int argc, char **argv) {
    int *a = new int[argc - 1];
    for (int i = 1; i < argc; i++) {
        a[i - 1] = atoi(argv[i]);
    }
    Solution s;
    int n = s.removeDuplicates(a, argc - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
