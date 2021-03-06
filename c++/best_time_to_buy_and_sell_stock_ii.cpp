/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
 * simple
*/

#include "helper.h"
#include <limits>

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            profit += std::max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};

int main() {
    Solution s;
    vector<int> prices({7, 1, 5, 3, 6, 4});
    cout << s.maxProfit(prices) << endl;
    return 0;
}
