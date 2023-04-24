/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2)));
        for (int i = 0; i < 3; i++) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int k = 2; k >= 1; k--) {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1]+prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0]-prices[i]);
            }
        }
        return dp[n-1][2][0];
    }
};
// @lc code=end

