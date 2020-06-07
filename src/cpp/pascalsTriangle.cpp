#include <vector>
#include <utility>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // initialize vector
        vector<vector<int> > array;
        for (int i = 1; i <= numRows; i++) {
            vector<int> a;
            for (int j = 0; j < i; j++) {
                a.push_back(1);
            }
            array.push_back(a);
        }

        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
            }
        }

        return array;
    }
};

int main(int argc, char **argv) {
    Solution s;
    int size = 5;
    if (argc > 1) {
        size = atoi(argv[1]);
    }
    vector<vector<int> > v = s.generate(size);
    for (int i = 0; i < size; i++) {
        for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }
    return 0;
}

