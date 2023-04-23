/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
/*
    // 原始版本
    int maxProfit(vector<int>& prices) {
        // k=1
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        // 初始化
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]);
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i]);
        }
        return dp[n-1][0];
    }
*/
    // 空间优化版本
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int not_have = 0;
        int have = -prices[0];
        int pre_nohave = 0;
        for (int i = 1; i < n; i++) {
            int ret = not_have;
            not_have = max(not_have, have+prices[i]);
            have = max(have, pre_nohave-prices[i]);
            pre_nohave = ret;
        }
        return not_have;
    }
};
// @lc code=end

