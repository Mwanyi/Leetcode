/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> trace;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return result;
    }
    void backtrack(vector<int>& nums, int start) {
        // 前序位置，直接加入result
        result.push_back(trace);

        for (int i = start; i < nums.size(); i++) {
            // 如果该位置元素与前面一致，就剪枝，因为前面的只遍历第一个即可
            if (i > start && nums[i] == nums[i-1]) {
                continue;
            }
            trace.push_back(nums[i]);
            backtrack(nums, i+1);
            // 后序位置，撤销选择
            trace.pop_back();
        }
    }
};
// @lc code=end

