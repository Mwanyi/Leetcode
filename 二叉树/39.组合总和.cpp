/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 * 子集/组合的元素无重可重复选
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> trace;
    int total = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
    void backtrack(vector<int>& candidates, int target, int start) {
        // 前序位置
        if (total == target) {
            result.push_back(trace);
            return ;
        }

        for (int i = start; i < candidates.size(); i++) {
            // 做选择
            total += candidates[i];
            if (total > target) {
                total -= candidates[i];
                continue;
            }
            trace.push_back(candidates[i]);
            backtrack(candidates, target, i);
            // 后序位置
            total -= candidates[i];
            trace.pop_back();
        }
    }
};
// @lc code=end

