/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k > n / 2) {
            int no_have = 0;
            int have = -prices[0];
            for (int i = 1; i < n; i++) {
                no_have = max(no_have, have+prices[i]);
                have = max(have, no_have-prices[i]);
            }
            return no_have;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2)));
        for (int i = 0; i <= k; i++) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};
// @lc code=end

