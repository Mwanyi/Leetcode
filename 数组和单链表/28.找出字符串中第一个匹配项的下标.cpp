/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
// kabin karp滑动窗口算法
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 位数
        int L = needle.size();
        // 进制数,ASCLL编码
        int R = 256;
        // 设置一个较大的素数作为hash码
        long Q = 1658598167;
        long RL =  1;
        for (int i = 1; i < L; i++) {
            RL = (RL*R) % Q;
        }
        // 计算匹配字符串的hash数
        long needlehash = 0;
        for (int i = 0; i < needle.size(); i++) {
            needlehash = (needlehash*R+needle[i]) % Q;
        }
        // 滑动窗口算法
        int left = 0, right = 0;
        long windowhash = 0;
        while (right < haystack.size()) {
            // 扩大窗口，就是将数字加入到当前窗口中
            windowhash = (windowhash*R+haystack[right]) % Q;
            right++;

            while (left < right && right-left == L) {
                if (windowhash == needlehash) {
                    // 还需进一步确认窗口子串是否真的和模式串相同，避免哈希冲突
                    if (needle == haystack.substr(left, L)) {
                        return left;
                    }
                }
                // 缩减窗口
                // 这里加上Q的原因是防止windowhash减之后为负值，加上Q可以防止为负值
                windowhash = (windowhash - (haystack[left]*RL)%Q+Q)%Q;
                left++;
            }
        }
        return -1;
    }
};
// @lc code=end

