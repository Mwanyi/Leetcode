/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0;
        int find = 0;
        while (find < nums.size()) {
            if (nums[find] == val) {
                find++;
            }
            else {
                nums[cur++] = nums[find++];
            }
        }
        return cur;
    }
};
// @lc code=end

