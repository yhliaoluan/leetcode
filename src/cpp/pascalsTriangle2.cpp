#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int i, j;
        vector<int> v;
        for (i = 0; i <= rowIndex; i++) {
            v.push_back(1);
        }

        for (i = rowIndex - 1; i > 0; i--) {
            for (j = i; j < v.size() - 1; j++) {
                v[j] = v[j] + v[j + 1];
            }
        }
        return v;
    }
};

int main(int argc, char **argv) {
    int index = 3;
    if (argc > 1) {
        index = atoi(argv[1]);
    }

    Solution s;
    vector<int> v = s.getRow(index);
    for (int i = 0; i < v.size(); i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
