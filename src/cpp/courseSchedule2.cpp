/*
 *There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 * */
#include "header.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> pre(numCourses, unordered_set<int>());
        vector<int> indegree(numCourses, 0);
        for (pair<int, int> &p : prerequisites) {
            if (pre[p.second].find(p.first) == pre[p.second].end()) {
                pre[p.second].insert(p.first);
                indegree[p.first]++;
            }
        }
        stack<int> zeroes;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                zeroes.push(i);
            }
        }
        vector<int> res;
        while (!zeroes.empty()) {
            int course = zeroes.top();
            zeroes.pop();
            for (int i : pre[course]) {
                if (--indegree[i] == 0) {
                    zeroes.push(i);
                }
            }
            res.push_back(course);
        }
        for (int ind : indegree) {
            if (ind > 0) { return vector<int>(); }
        }
        return res;
    }
};

int main(int argc, char **argv) {
    vector<pair<int, int>> prerequisites;
    for (int i = 2; i < argc; i += 2) {
        prerequisites.push_back(make_pair(atoi(argv[i]), atoi(argv[i + 1])));
    }
    print_vector(Solution().findOrder(atoi(argv[1]), prerequisites));
}
