#ifndef _LEETCODE_HEADER_H_
#define _LEETCODE_HEADER_H_

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <unordered_map>
#include <cstring>
using namespace std;

template <class T>
static void print_grid(vector<vector<T> > &grid) {
    cout << "<<<<" << endl;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << ">>>>" << endl;
}

#endif
