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

typedef struct _st_Node {
    int val;
    int i;
} Node;

bool sort_node(Node &n1, Node &n2) {
    return n1.val < n2.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> nodes;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            Node n = { numbers[i], i };
            nodes.push_back(n);
        }
        sort(nodes.begin(), nodes.end(), sort_node);
        int low = 0;
        int high = nodes.size() - 1;
        while (low < high) {
            if (nodes[low].val + nodes[high].val == target) {
                if (nodes[low].i < nodes[high].i) {
                    result.push_back(nodes[low].i + 1);
                    result.push_back(nodes[high].i + 1);
                } else {
                    result.push_back(nodes[high].i + 1);
                    result.push_back(nodes[low].i + 1);
                }
                break;
            } else if (nodes[low].val + nodes[high].val < target) {
                while (++low < high && nodes[low].val == nodes[low - 1].val) ;
            } else {
                while (--high > low && nodes[high].val == nodes[high + 1].val) ;
            }
        }
        return result;
    }
};

static Solution s;

int main(int argc, char **argv) {
    vector<int> numbers;
    for (int i = 1; i < argc - 1; i++) {
        numbers.push_back(atoi(argv[i]));
    }
    vector<int> result = s.twoSum(numbers, atoi(argv[argc - 1]));
    printf("%d %d\n", result[0], result[1]);
    return 0;
}
