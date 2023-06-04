/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        // 存储一个遍历时的路径
        vector<int> trace;
        // 显式表示选择，来记录该点有没有被选择
        vector<bool> used(nums.size(), false);
        backtrace(nums, trace, used);
        return result;
    }

    void backtrace(vector<int>&nums, vector<int>& trace, vector<bool>& used) {
        if (trace.size() == nums.size()) {
            result.push_back(trace);
            return ;
        }
        for (int i = 0; i < used.size(); i++) {
            if (used[i]) {
                continue;
            }
            // 选择
            used[i] = true;
            trace.push_back(nums[i]);
            backtrace(nums, trace, used);
            // 撤销选择
            used[i] = false;
            trace.pop_back();
        }
    }
};
// @lc code=end

