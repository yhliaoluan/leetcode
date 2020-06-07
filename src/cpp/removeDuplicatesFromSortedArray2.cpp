/*
 * Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 
 * */
#include "header.h"

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) { return 0; }
        int left, right, count;
        left = right = count = 1;
        while (right < n) {
            if (A[right] == A[right - 1]) {
                if (++count < 3) {
                    A[left++] = A[right];
                }
            } else {
                count = 1;
                A[left++] = A[right];
            }
            right++;
        }
        return left;
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    for (int i = 1; i < argc; i++) {
        v.push_back(atoi(argv[i]));
    }
    Solution s;
    int count = s.removeDuplicates(&v[0], v.size());
    for (int i = 0; i < count; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
