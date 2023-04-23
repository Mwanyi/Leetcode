/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
/*
    // 原始解法
    int maxProfit(vector<int>& prices) {
        // k=无穷,因此也不需要关于k的数组
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        // 初始化
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            // dp[i-1][k-1][0] == dp[i-1][k][0]
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
*/
    // 节省空间
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int not_have = 0;
        int have = -prices[0];
        for (int i = 1; i < n; i++) {
            int pre_nothave = not_have;
            not_have = max(not_have, have+prices[i]);
            have = max(have, pre_nothave-prices[i]);
        }
        return not_have;
    }
};
// @lc code=end

