/*
 * Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem. 
 * */
#include "header.h"

class Solution {
public:
    void sortColors(int A[], int n) {
        int low = 0;
        int up = n - 1;
        for (int i = 0; i <= up;) {
            if (A[i] == 0) {
                swap(A[i++], A[low++]);
            } else if (A[i] == 2) {
                swap(A[i], A[up--]);
            } else {
                i++;
            }
        }
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    int n;
    while (cin >> n)
        v.push_back(n);
    Solution s;
    s.sortColors(&v[0], v.size());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
