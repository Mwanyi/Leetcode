/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> trace; 
    int total = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
    }
    void backtrack(vector<int>& candidates, int target, int start) {
        // 前序位置，如果总和等于target，则加入
        if (total == target) {
            result.push_back(trace);
            return ;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i-1] == candidates[i]) {
                continue;
            }
            if ((total+candidates[i]) > target) {
                break;
            }
            total += candidates[i];
            trace.push_back(candidates[i]);
            backtrack(candidates, target, i+1);
            // 后序位置
            total -= candidates[i];
            trace.pop_back();
        }
    }
};
// @lc code=end

