/*
 *Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
 * */
#include "header.h"

class Solution {
public:
    string simplifyPath(string path) {
        string tmp, res;
        vector<string> paths;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".") continue;
            else if (tmp == ".." && !paths.empty()) paths.pop_back();
            else if (tmp != "..") paths.push_back(tmp);
        }
        for (auto str : paths) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};

int main(int argc, char **argv) {
    Solution s;
    cout << s.simplifyPath(argv[1]) << endl;
    return 0;
}
