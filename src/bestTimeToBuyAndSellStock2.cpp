/*
 *Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * */
#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else {
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};

int main(int argc, char **argv) {
    vector<int> prices;
    for (int i = 1; i < argc; i++) {
        prices.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
}
