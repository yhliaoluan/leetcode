#ifndef _LEETCODE_HEADER_H_
#define _LEETCODE_HEADER_H_

#include <limits.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <unordered_map>
#include <map>
#include <cstring>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
static void print_list(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

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

template <class T>
static void print_vector(const vector<T> &vec) {
    cout << "size:" << vec.size() << " ";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "END" << endl;
}

template <class T>
static vector<vector<T> > read_grid() {
    vector<vector<T> > matrix;
    string s;
    while (getline(cin, s, '\n')) {
        stringstream ss(s);
        T n;
        vector<T> line;
        while (ss >> n) {
            line.push_back(n);
        }
        matrix.push_back(line);
    }
    return matrix;
}

#endif
