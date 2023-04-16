/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> trace;
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
    void backtrack(int n, int k, int start) {
        if (trace.size() == k) {
            result.push_back(trace);
            return ;
        }
        for (int i = start; i <= n; i++) {
            trace.push_back(i);
            backtrack(n, k, i+1);
            trace.pop_back();
        }
    }
};
// @lc code=end

