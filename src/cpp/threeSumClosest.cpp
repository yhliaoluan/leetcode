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
        int sum = num[0] + num[1] + num[2];
        int a = abs(sum - target);
        for (int i = 0; i < num.size() - 2; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int low = i + 1;
            int high = num.size() - 1;
            int tar = target - num[i];
            while (low < high) {
                if (num[low] + num[high] == tar) {
                    return num[low] + num[high] + num[i];
                } else if (num[low] + num[high] > tar) {
                    if (abs(num[low] + num[high] + num[i] - target) < a) {
                        sum = num[i] + num[low] + num[high];
                        a = abs(sum - target);
                    }
                    while (--high > low && num[high] == num[high + 1]) ;
                } else {
                    if (abs(num[low] + num[high] + num[i] - target) < a) {
                        sum = num[i] + num[low] + num[high];
                        a = abs(sum - target);
                    }
                    while (++low < high && num[low] == num[low - 1]) ;
                }
            }
        }
        return sum;
    }
};

int main(int argc, char **argv) {
    vector<int> nums;
    for (int i = 1; i < argc - 1; i++) {
        nums.push_back(atoi(argv[i]));
    }
    Solution s;
    printf("%d\n", s.threeSumClosest(nums, atoi(argv[argc - 1])));
}
