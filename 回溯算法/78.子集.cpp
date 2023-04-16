/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> trace;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return result;
    }
    void backtrack(vector<int>& nums, int start) {
        // 前序位置就是进入的位置，直接加入result中
        result.push_back(trace);

        for (int i = start; i < nums.size(); i++) {
            trace.push_back(nums[i]);
            backtrack(nums, i+1);
            // 后序位置，撤销操作
            trace.pop_back();
        }
    }
};
// @lc code=end

