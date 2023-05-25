/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char, int> need, window;
        for (char c : p) {
            need[c]++;
        }
        int left = 0, right = 0;
        int vaild = 0;
        while (right < s.size()) {
            // 增加窗口
            char cur = s[right++];
            if (need.count(cur)) {
                window[cur]++;
                if (window[cur] == need[cur]) {
                    vaild++;
                }
            }
            // 缩减窗口
            while (left < right && right - left >= p.size()) {
                if (vaild == need.size()) {
                    result.push_back(left);
                }
                // 缩减窗口
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        vaild--;
                    }
                    window[d]--;
                }
            }
        }
        return result;
    }
};
// @lc code=end

