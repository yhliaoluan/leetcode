/*
 *Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 * */
#include "header.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN;
        int hold2 = INT_MIN;
        int release1 = 0;
        int release2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            release2 = max(release2, hold2 + prices[i]);
            hold2 = max(hold2, release1 - prices[i]);
            release1 = max(release1, hold1 + prices[i]);
            hold1 = max(hold1, -prices[i]);
        }
        return release2;
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
