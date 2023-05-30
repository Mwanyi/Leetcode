/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int f(vector<int>& nums, int c) {
        int day = 0;
        int total = 0;
        for (int num : nums) {
            total += num;
            if (total > c) {
                day++;
                total = num;
            }
        }
        if (total > 0) {
            day++;
        }
        return day;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = 0, right = 0;
        for (int num : nums) {
            left = max(left, num);
            right += num;
        }
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (f(nums, mid) <= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

