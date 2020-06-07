/*
 *There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 * */
#include "header.h"
struct Vertex {
    int indegree;
    vector<int> nexts;
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Vertex> vertexes(numCourses);
        for (pair<int, int> &p : prerequisites) {
            vertexes[p.first].nexts.push_back(p.second);
            vertexes[p.second].indegree++;
        }
        queue<Vertex> q;
        for (Vertex &v : vertexes) {
            if (v.indegree == 0) {
                q.push(v);
            }
        }
        while (!q.empty()) {
            Vertex &v = q.front();
            for (int next : v.nexts) {
                if (--vertexes[next].indegree == 0) {
                    q.push(vertexes[next]);
                }
            }
            q.pop();
        }
        for (Vertex &v : vertexes) {
            if (v.indegree != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char **argv) {
    vector<pair<int, int> > prerequisites;
    for (int i = 1; i < argc - 1; i += 2) {
        prerequisites.push_back(make_pair(atoi(argv[i]), atoi(argv[i + 1])));
    }
    cout << Solution().canFinish(atoi(argv[argc - 1]), prerequisites) << endl;
    return 0;
}
