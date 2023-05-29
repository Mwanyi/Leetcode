/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    // 二分查找
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int firstleft = 0, firstright = nums.size()-1;
        int lastleft = 0, lastright = nums.size()-1;
        // 找左边界
        while (firstleft <= firstright) {
            int mid = firstleft + (firstright-firstleft)/2;
            if (nums[mid] == target) {
                firstright = mid-1;
            }
            else if(nums[mid] < target) {
                firstleft = mid+1;
            }
            else if(nums[mid] > target) {
                firstright = mid-1;
            }
        }
        if (firstleft == nums.size()) result.push_back(-1);
        else {
            result.push_back(nums[firstleft] == target ? firstleft : -1);
        }

        // 找右边界
        while (lastleft <= lastright) {
            int mid = lastleft + (lastright-lastleft)/2;
            if (nums[mid] == target) {
                lastleft = mid+1;
            }
            else if(nums[mid] < target) {
                lastleft = mid+1;
            }
            else if(nums[mid] > target) {
                lastright = mid-1;
            }
        }
        if (lastleft-1 < 0) result.push_back(-1);
        else {
            result.push_back(nums[lastleft-1] == target ? lastleft-1 : -1);
        }
        return result;
    }
};
// @lc code=end

