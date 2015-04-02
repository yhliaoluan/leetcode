/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 ¡ú 1,3,2
3,2,1 ¡ú 1,2,3
1,1,5 ¡ú 1,5,1
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        for (int i = (int)num.size() - 1; i > 0; i--) {
            if (num[i] > num[i - 1]) {
                for (int j = num.size() - 1; ; j--) {
                    if (num[j] > num[i - 1]) {
                        std::swap(num[i - 1], num[j]);
                        std::reverse(num.begin() + i, num.end());
                        return;
                    }
                }
            }
        }
        std::reverse(num.begin(), num.end());
    }
};

int main(int argc, char **argv) {
    vector<int> num;
    for (int i = 1; i < argc; i++) {
        num.push_back(atoi(argv[i]));
    }
    Solution s;
    s.nextPermutation(num);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    return 0;
}