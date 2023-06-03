/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        // 维系一个isstack数组来存储当前字符是否已经进栈
        vector<bool> isstack(256, false);
        // 维系一个栈来进行入栈出栈操作，保证顺序不变
        stack<char> sta;
        // 维系count数组来保存每个字符还有多少没有被遍历
        vector<int> count(256);
        for (char c : s) {
            count[c]++;
        }
        for (char c : s) {
            count[c]--;
            // 如果当前字符已经在栈中，则不做任何操作
            if (isstack[c]) {
                continue;
            }
            // 如果当前字符小于栈顶元素
            while (!sta.empty() && c < sta.top()) {
                if (count[sta.top()] == 0) {
                    break;
                }
                isstack[sta.top()] = false;
                sta.pop();
            }
            // 插入当前元素
            isstack[c] = true;
            sta.push(c);
        }
        string result(sta.size(), ' ');
        for (int i = sta.size()-1; i >= 0; i--) {
            result[i] = sta.top();
            sta.pop();
        }
        //result.reserve();
        return result;
    }
};
// @lc code=end

