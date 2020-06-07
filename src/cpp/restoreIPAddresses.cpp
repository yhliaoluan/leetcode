/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include "header.h"
static int analyse1(string s, int i) {
    if (i >= s.size()) { return -1; }
    return stoi(s.substr(i, 1));
}
static int analyse2(string s, int i) {
    if (i + 1 >= s.size() || s[i] == '0') { return -1; }
    return stoi(s.substr(i, 2));
}
static int analyse3(string s, int i) {
    if (i + 2 >= s.size() || s[i] == '0') { return -1; }
    int val = stoi(s.substr(i, 3));
    if (val > 255) { return -1; }
    else return val;
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        typedef int (*ana_func)(string s, int i);
        ana_func func[3] = { analyse1, analyse2, analyse3 };
        for (int i = 0; i < 3; i++) {
            int v1 = func[i](s, 0);
            if (v1 < 0) { continue; }
            for (int j = 0; j < 3; j++) {
                int v2 = func[j](s, i + 1);
                if (v2 < 0) { continue; }
                for (int m = 0; m < 3; m++) {
                    int v3 = func[m](s, i + j + 2);
                    if (v3 < 0) { continue; }
                    for (int n = 0; n < 3; n++) {
                        if (i + j + m + n + 4 != s.size()) { continue; }
                        int v4 = func[n](s, i + j + m + 3);
                        if (v4 < 0) { continue; }
                        stringstream ss;
                        ss << v1 << "." << v2 << "." << v3 << "." << v4;
                        result.push_back(ss.str());
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Solution s;
    vector<string> result = s.restoreIpAddresses(argv[1]);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}