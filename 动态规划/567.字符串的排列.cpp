/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char c: s1) {
            need[c]++;
        }
        int left = 0, right = 0;
        int vaild = 0;
        while (right < s2.size()) {
            char cur = s2[right];
            right++;
            if (need.count(cur)) {
                window[cur]++;
                if (window[cur] == need[cur]) {
                    vaild++;
                }
            }

            while (left < right && right-left >= s1.size()) {
                if (vaild == need.size()) {
                    return true;
                }
                char d = s2[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        vaild--;
                    }
                    window[d]--;
                }
            }
        }
        return false;
    }
};
// @lc code=end

