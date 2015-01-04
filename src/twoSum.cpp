/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */

#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

typedef struct Node {
    int value;
    int index;
} Node;

static bool sort_func(Node n1, Node n2) {
    return n1.value < n2.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> nodes;
        for (int i = 0; i < numbers.size(); i++) {
            Node node = { numbers[i], i + 1 };
            nodes.push_back(node);
        }

        sort(nodes.begin(), nodes.end(), sort_func);

        vector<int> result;
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i].value > target) {
                continue;
            }
            for (int j = i + 1; j < nodes.size(); j++) {
                if (nodes[i].value + nodes[j].value == target) {
                    if (nodes[i].index < nodes[j].index) {
                        result.push_back(nodes[i].index);
                        result.push_back(nodes[j].index);
                    } else {
                        result.push_back(nodes[j].index);
                        result.push_back(nodes[i].index);
                    }
                    return result;
                } else if (nodes[i].value + nodes[j].value > target) {
                    break;
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    int n;
    vector<int> vec;
    while (scanf("%d", &n)) {
        vec.push_back(n);
    }

    int target = vec.back();
    vec.pop_back();

    printf("input: ");
    for (int i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    printf("target: %d\n", target);

    Solution s;
    vector<int> result = s.twoSum(vec, target);
    printf("%d %d\n", result[1], result[2]);

    return 0;
}
