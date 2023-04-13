/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        int find = 1;
        while (find < nums.size()) {
            if (nums[find] == nums[cur]) {
                find++;
            }
            else {
                nums[++cur] = nums[find++];
            }
        }
        return cur+1;
    }
};
// @lc code=end

