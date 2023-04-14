/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 第i金额对应的最小硬币数
        vector<int> dp(amount+1, amount+1);
        // 初始化
        dp[0] = 0;
        // 对每一个金额
        for (int i = 0; i < dp.size(); i++) {
            for (int coin : coins) {
                if (i-coin < 0) {
                    continue;
                }
                // 状态转移方程
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return (dp[amount] == amount+1)? -1 : dp[amount];
    }
};
// @lc code=end

