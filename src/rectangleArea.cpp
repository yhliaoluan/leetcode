/*
 *Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
Rectangle Area

Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
 * */
#include "header.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (D - B) * (C - A) + (H - F) * (G - E);
        if (E > C || A > G || B > H || F > D) return area;
        int crossArea = min(H - B, min(D - F, min(H - F, D - B))) *
            min(C - E, min(G - A, min(G - E, C - A)));
        return area - crossArea;
    }
};

int main(int argc, char **argv) {
    cout << Solution().computeArea(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]),
        atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]),
        atoi(argv[8])) << endl;
    return 0;
}
