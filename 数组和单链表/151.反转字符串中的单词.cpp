/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        // 先翻转整个字符
        s = reverseword(s, 0, n-1);
        string result;
        // 再单独翻转每个单词
        int begin = 0;
        int end = 0;
        while (end < n) {
            while (begin < n && s[begin] == ' ') {
                begin++;
            }
            end = begin+1;
            while (end < n && s[end] != ' ') {
                end++;
            }
            if (begin < n && end < n) {
                result += reverseword(s, begin, end-1);
                result += ' ';
                begin = end;
            }
        }
        if (begin < n) {
            result += reverseword(s, begin, n-1);
            return result;
        }
        return result.substr(0, result.size()-1);
    }
    string reverseword(string s, int begin, int end) {
        int left = begin, right = end;
        while (begin < end) {
            char c = s[begin];
            s[begin] = s[end];
            s[end] = c;
            begin++;
            end--;
        }
        return s.substr(left, right-left+1);
    }
};
// @lc code=end

