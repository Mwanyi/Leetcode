/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
/*
    // 原始版本
    int maxProfit(vector<int>& prices, int fee) {
        // k=无穷
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0]-fee;

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee);
        }
        return dp[n-1][0];
    }
*/
    // 优化空间版本
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int no_have = 0;
        int have = -prices[0]-fee;
        for (int i = 1; i < n; i++) {
            no_have = max(no_have, have+prices[i]);
            have = max(have, no_have-prices[i]-fee);
        }
        return no_have;
    }
};
// @lc code=end

