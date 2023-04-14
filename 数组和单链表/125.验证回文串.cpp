/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char & c : s) {
            if (isalnum(c)) {
                str += tolower(c);
            }
        }
        int begin = 0;
        int end = str.size()-1;
        while (begin <= end) {
            if (str[begin] != str[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};
// @lc code=end

