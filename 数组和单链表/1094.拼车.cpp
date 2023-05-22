/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
// 差分数组
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        for (vector<int>& trip : trips) {
            increment(trip[1], trip[2]-1, trip[0], diff);
        }
        vector<int> result(1001);
        result[0] = diff[0];
        if (result[0] > capacity) {
            return false;
        }
        for (int i = 1; i <1001; i++) {
            result[i] = result[i-1]+diff[i];
            if (result[i] > capacity) {
                return false;
            }
        }
        return true;
    }
    void increment(int i, int j, int val, vector<int>& diff) {
        diff[i] += val;
        if (j+1 < diff.size()) {
            diff[j+1] -= val;
        }
    }
};
// @lc code=end

