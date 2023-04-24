/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
/*
    // 原始解法
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
*/

    // 节省空间
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int pre_pre = nums[0];
        int pre = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int ret = pre;
            pre = max(pre, pre_pre+nums[i]);
            pre_pre = ret;
        }
        return pre;
    }
};
// @lc code=end

