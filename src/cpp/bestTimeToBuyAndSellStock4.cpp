/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/
#include "header.h"

static int max_profit_2(int k, vector<int> &prices) {
    vector<int> buy(k + 1, INT_MIN);
    vector<int> sell(k + 1, 0);
    for (int i = 0; i < prices.size(); i++) {
        for (int j = 1; j <= k; j++) {
            sell[j] = max(sell[j], buy[j] + prices[i]);
            buy[j] = max(buy[j], sell[j - 1] - prices[i]);
        }
    }
    return sell[k];
}

static int max_profit(int k, vector<int> &prices) {
    vector<vector<int> > f(k + 1, vector<int>(prices.size(), 0));
    int balance;
    for (int i = 1; i <= k; i++) {
        balance = -prices[0];
        for (int j = 1; j < prices.size(); j++) {
            f[i][j] = max(f[i][j - 1], balance + prices[j]);
            balance = max(balance, f[i - 1][j - 1] - prices[j]);
        }
    }
}

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k > prices.size() / 2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                profit += max(0, prices[i] - prices[i - 1]);
            }
            return profit;
        }
        return max_profit_2(k, prices);
    }
};

int main(int argc, char **argv) {
    vector<int> prices;
    for (int i = 1; i < argc - 1; i++) {
        prices.push_back(atoi(argv[i]));
    }
    cout << Solution().maxProfit(atoi(argv[argc - 1]), prices) << endl;
    return 0;
}