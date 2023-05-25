/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 滑动窗口类问题
        // need用于记录要满足的字符，window是当前窗口记录的字符
        unordered_map<char, int> need, window;
        for (char c : t) {
            need[c]++;
        }
        int start = 0, len = __INT_MAX__;
        int left = 0, right = 0;
        // 记录满足条件的字符数，当vaild==need.size时表示可以开始收缩窗口
        int vaild = 0;
        while (right < s.size()) {
            // 扩大窗口
            char cur = s[right];
            right++;
            // 更新窗口
            if (need.count(cur)) {
                window[cur]++;
                if (window[cur] == need[cur]) {
                    vaild++;
                }
            }
            // 满足缩小窗口的条件
            while (left < right && vaild == need.size()) {
                // 更新最小字符下标
                if (right-left < len) {
                    start = left;
                    len = right-left;
                }
                // 缩小窗口
                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        vaild--;
                    }
                    window[d]--;
                }
            }
        }
        return len == __INT_MAX__? "" : s.substr(start, len);
    }
};
// @lc code=end

