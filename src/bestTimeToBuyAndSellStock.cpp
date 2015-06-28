/*
 *Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 * */
#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = max = prices[i];
            } else {
                max = prices[i];
                profit = std::max(profit, max - min);
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
