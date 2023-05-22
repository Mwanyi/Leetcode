/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> pre_num;
    NumArray(vector<int>& nums) {
        pre_num.resize(nums.size()+1);
        for (int i = 1; i < nums.size()+1; i++) {
            pre_num[i] = pre_num[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return pre_num[right+1]-pre_num[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

