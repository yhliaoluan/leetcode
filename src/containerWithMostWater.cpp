/*
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
 * */

#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int mx = 0;
        int low = 0;
        int high = height.size() - 1;
        while (low < high) {
            mx = max(mx, min(height[low], height[high]) * (high - low));
            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }
        return mx;
    }
};

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    vector<int> height;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        height.push_back(x);
    }
    Solution s;
    printf("%d\n", s.maxArea(height));
    return 0;
}
