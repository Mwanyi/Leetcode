/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> trace;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used);
        return result;
    }
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (trace.size() == nums.size()) {
            result.push_back(trace);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            // 注意这里需要增加一个!used[i-1]，因为如果前一个被选了，代表已经进入了下一层
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) {
                continue;
            }
            trace.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used);
            // 后序位置
            trace.pop_back();
            used[i] = false;
        }
    }
};
// @lc code=end

