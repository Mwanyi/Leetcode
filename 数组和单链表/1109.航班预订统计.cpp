/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
// 差分数组
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+1);
        for (vector<int>& book : bookings) {
            increment(book[0], book[1], book[2], diff);
        }
        vector<int> result(n);
        result[0] = diff[1];
        for (int i = 1; i < n; i++) {
            result[i] = diff[i+1] + result[i-1];
        }
        return result;
    }
    
    void increment(int i, int j, int val, vector<int>& diff) {
        diff[i] += val;
        if (j+1 < diff.size()) {
            diff[j+1] -= val;
        }
    }
};
// @lc code=end

