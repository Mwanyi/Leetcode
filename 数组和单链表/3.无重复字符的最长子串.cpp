/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int len = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            char cur = s[right++];
            window[cur]++;
            while (left < right && window[cur] > 1) {
                char d = s[left++];
                if (window.count(d)) {
                    window[d]--;
                }
            }
            len = max(len, right-left);
        }
        return len;
    }
};
// @lc code=end

