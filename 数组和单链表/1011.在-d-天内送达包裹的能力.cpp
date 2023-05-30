/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    // 输入单天运载能力，输出需要天数
    int f(vector<int>& weights, int c) {
        int day = 0;
        for (int i = 0; i < weights.size(); ) {
            int total = c;
            while (i < weights.size()) {
                if (total < weights[i]) break;
                else total -= weights[i];
                i++;
            }
            day++;
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0, right = 0;
        for (int weight : weights) {
            right += weight;
            left = max(left, weight);
        }
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (f(weights, mid) <= days) {
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

