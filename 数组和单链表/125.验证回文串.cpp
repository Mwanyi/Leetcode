/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        s = s.lower();
        int begin = 0;
        int end = s.size()-1;
        while (begin <= end) {
            if (s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};
// @lc code=end

