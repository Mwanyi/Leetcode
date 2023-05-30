/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    // 通过速度计算出此时吃完所有需要的时间
    long f(vector<int>& pils, int k) {
        long hours = 0;
        for (int pils : pils) {
            hours += pils / k;
            if (pils % k > 0) {
                hours++;
            }
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // 这里k取值最小为1，最大为每小时最大香蕉数
        int left = 1, right = 0;
        for (int pile : piles) {
            right = max(right, pile);
        }
        // 找最小的k，所以为左边界二分搜索
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (f(piles, mid) <= h) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return left;
    }
};
// @lc code=end

