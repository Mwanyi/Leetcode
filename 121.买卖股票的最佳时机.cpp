/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
/*
    // 初始解法
    int maxProfit(vector<int>& prices) {
        // k = 1,所以关于k的数组不需要，直接创建二维数组即可
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        // 初始化
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            // dp[i-1][0][0]中初始化为0，因此直接忽略即可
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }
        return dp[n-1][0];
    }
*/
    // 节省空间
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int have = -prices[0];
        int not_have = 0;
        for (int i = 1; i < n; i++) {
            not_have = max(not_have, have+prices[i]);
            have = max(have, -prices[i]);
        }
        return not_have;
    }
};
// @lc code=end

