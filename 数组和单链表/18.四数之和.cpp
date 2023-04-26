/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return nSumTarget(nums, 4, 0, target);
    }

    vector<vector<int>> nSumTarget(vector<int>& nums, int n, int start, long long target) {
    int sz = nums.size();
    vector<vector<int>> res;
    if (n < 2 || sz < n) return res;
    if (n == 2) {
        int left = start;
        int right = sz-1;
        while (left < right) {
            long long num = nums[left] + nums[right];
            int l = nums[left];
            int r = nums[right];
            if (num > target) {
                while (left < right && nums[right] == r) right--;
            } 
            else if (num < target) {
                while (left < right && nums[left] == l) left++;
            }
            else {
                res.push_back({l, r});
                while (left < right && nums[right] == r) right--;
                while (left < right && nums[left] == l) left++;
            }
        }
    }
    else {
        for (int i = start; i < sz; i++) {
            vector<vector<int>> sub = nSumTarget(nums, n-1, i+1, target-nums[i]);
            for (vector<int>& v : sub) {
                v.push_back(nums[i]);
                res.push_back(v);
            }
            while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    return res;
}
};
// @lc code=end

