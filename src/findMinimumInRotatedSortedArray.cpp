#include <vector>
#include <stdio.h>

using namespace std;
class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size() - 1);
    }
private:
    int findMin(vector<int> &num, int from, int to) {
        if (from == to) {
            return num[from];
        }
        if (num[(from + to) / 2] > num[to]) {
            return findMin(num, (from + to) / 2 + 1, to);
        } else {
            return findMin(num, from, (from + to) / 2);
        }
    }
};

int main(int argc, char **argv) {
    vector<int> v;
    int value;
    while (scanf("%d", &value)) {
        v.push_back(value);
    }
    printf("total %d elements\n", v.size());
    Solution s;
    printf("%d\n", s.findMin(v));
}
