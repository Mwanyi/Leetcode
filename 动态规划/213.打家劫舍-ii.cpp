/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(rob_(nums, 0, n-1), rob_(nums, 1, n));
    }

    int rob_(vector<int>& nums, int start, int end) {
        int n = end-start;
        if (n == 1) {
            return nums[start];
        }
        int pre_pre = nums[start];
        int pre = max(nums[start], nums[start+1]);
        for (int i = start+2; i < end; i++) {
            int ret = pre;
            pre = max(pre, pre_pre+nums[i]);
            pre_pre = ret;
        }
        return pre;
    }
};
// @lc code=end

