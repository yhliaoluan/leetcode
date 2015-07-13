/*
 *There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
 * */

#include "header.h"

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) { return 0; }
        if (ratings.size() == 1) { return 1; }
        vector<int> candies(ratings.size(), 0);
        beginToEnd(ratings, candies);
        endToBegin(ratings, candies);
        int count = 0;
        for (int i : candies) {
            count += i;
        }
        return count;
    }

    void beginToEnd(vector<int> &ratings, vector<int> &candies) {
        int i = 0;
        if (ratings[i] <= ratings[i + 1]) {
            candies[i] = 1;
        }
        for (i = 1; i < ratings.size() - 1; i++) {
            if (ratings[i] <= ratings[i - 1] &&
                ratings[i] <= ratings[i + 1]) {
                candies[i] = 1;
            } else if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        } else {
            candies[i] = 1;
        }
    }

    void endToBegin(vector<int> &ratings, vector<int> &candies) {
        for (int i = ratings.size() - 2; i > 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                if (ratings[i] <= ratings[i - 1]) {
                    candies[i] = candies[i + 1] + 1;
                } else {
                    candies[i] = max(candies[i + 1], candies[i - 1]) + 1;
                }
            }
        }
        if (ratings[0] > ratings[1]) {
            candies[0] = candies[1] + 1;
        }
    }
};

int main(int argc, char **argv) {
    vector<int> ratings;
    for (int i = 1; i < argc; i++) {
        ratings.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.candy(ratings) << endl;
    return 0;
}
