/*
 *Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
 * */
#include "header.h"
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) { return NULL; }
        if (m.find(node) == m.end()) {
            UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
            m.insert(make_pair(node, copy));
            for (auto child : node->neighbors) {
                copy->neighbors.push_back(cloneGraph(child));
            }
        }
        return m[node];
    }
};

int main(int argc, char **argv) {
    unordered_set<int> added;
    UndirectedGraphNode node1(1);
    UndirectedGraphNode node2(2);
    UndirectedGraphNode node3(3);
    node1.neighbors.push_back(&node2);
    node2.neighbors.push_back(&node3);
    node3.neighbors.push_back(&node1);
    Solution s;
    UndirectedGraphNode *copy = s.cloneGraph(&node1);
    cout << copy->label << " child:" << copy->neighbors.size() << endl;
    return 0;
}
