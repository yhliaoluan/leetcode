/*
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */
#include <stdio.h>

#ifndef min
#define min(x,y) (x) < (y) ? (x) : (y)
#endif

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) & 0x01) {
            return findKthNum(A, m, B, n, (m + n + 1) / 2);
        } else {
            return (findKthNum(A, m, B, n, (m + n) / 2) + 
                findKthNum(A, m, B, n, (m + n) / 2 + 1)) / 2;
        }
    }

private:
    double findKthNum(int *A, int m, int *B, int n, int k) {
//        printf("m:%d - ", m);
//        for (int i = 0; i < m; i++) {
//            printf("%d ", A[i]);
//        }
//        printf("n:%d - ", n);
//        for (int i = 0; i < n; i++) {
//            printf("%d ", B[i]);
//        }
//        printf("k:%d\n", k);
        if (m > n) {
//            printf("reverse\n");
            return findKthNum(B, n, A, m, k);
        }

        if (m == 0) {
//            printf("return B[k-1]\n");
            return B[k-1];
        }

        if (k == 1) {
//            printf("return min A[0] B[0]\n");
            return min(A[0], B[0]);
        }

        int pa = min(k/2, m);
        int pb = k - pa;
        if (A[pa - 1] < B[pb - 1]) {
            return findKthNum(A + pa, m - pa, B, n, k - pa);
        } else if (A[pa - 1] > B[pb - 1]) {
            return findKthNum(A, m, B + pb, n - pb, k - pb);
        } else {
            return A[pa - 1];
        }
    }
};

int main(int argc, char **argv) {
    int m, n;
    int A[1024];
    int B[1024];
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    Solution s;
    double value = s.findMedianSortedArrays(A, m, B, n);
    printf("%f", value);

    return 0;
}
