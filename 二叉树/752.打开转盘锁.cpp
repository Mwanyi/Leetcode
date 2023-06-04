/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include <queue>
class Solution {
public:
    // BFS
    string PlusString(string s, int index) {
        if (s[index] == '9') {
            s[index] = '0';
        }
        else {
            s[index] = (s[index]-'0'+1)+'0';
        }
        return s;
    }
    string MinusString(string s, int index) {
        if (s[index] == '0') {
            s[index] = '9';
        }
        else {
            s[index] = (s[index]-'0'-1)+'0';
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> visited;
        unordered_set<string> deadend;
        for (string s : deadends) {
            deadend.insert(s);
        }
        q.push("0000");
        visited.insert("0000");
        int depth = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                // 在死亡数字中
                if (deadend.count(cur)) {
                    continue;
                }
                if (cur == target) {
                    return depth;
                }
                for (int j = 0; j < 4; j++) {
                    string ps = PlusString(cur, j);
                    if (visited.count(ps) == 0) {
                        q.push(ps);
                        visited.insert(ps);
                    }
                    string ms = MinusString(cur, j);
                    if (visited.count(ms) == 0) {
                        q.push(ms);
                        visited.insert(ms);
                    }
                }
            }
            depth++;
        }
        return -1;
    }
};
// @lc code=end

