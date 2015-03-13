/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * */
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int near = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size() - 2; i++) {
            for (int j = i + 1; j < num.size() - 1; j++) {
                int third = findNearest(num, j + 1, j + 1, num.size() - 1, target - num[i] - num[j]);
                if (abs(near - target) > abs(num[i] + num[j] + third - target)) {
                    near = num[i] + num[j] + third;
                }
            }
        }

        return near;
    }
private:
    int findNearest(vector<int> &num, int lower, int from, int to, int target) {
        if (from == to) {
            int nearest = num[from];
            if (from - 1 >= lower) {
                if (abs(target - num[from - 1]) < abs(target - nearest)) {
                    nearest = num[from - 1];
                }
            }
            if (from + 1 < num.size()) {
                if (abs(target - num[from + 1]) < abs(target - nearest)) {
                    nearest = num[from + 1];
                }
            }
            return nearest;
        }

        int index = (from + to) / 2;
        if (num[index] < target) {
            return findNearest(num, lower, index + 1, to, target);
        } else if (num[index] > target) {
            return findNearest(num, lower, from, index, target);
        } else {
            return target;
        }
    }
};

int main(int argc, char **argv) {
    int n, target;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        nums.push_back(num);
    }
    scanf("%d", &target);

    Solution s;
    printf("%d\n", s.threeSumClosest(nums, target));
}
