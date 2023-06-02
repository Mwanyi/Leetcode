/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
class Solution {
public:
    int sz = 0;
    unordered_map<int, int> IndexToVal;

    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        // 先标记一下，防止有黑名单数字占用其他黑名单的位置
        for (int b : blacklist) {
            IndexToVal[b] = 1;
        }
        int last = n-1;
        for (int b : blacklist) {
            if (b >= sz) {
                continue;
            }
            // last本身就属于黑名单数字，则不需要移动到前面
            while (IndexToVal.count(last)) {
                last--;
            }
            // 将当前index为b的数字变为last，也就是把last移到前面来
            IndexToVal[b] = last;
            last--;
        }
    }
    
    int pick() {
        // 随机在[0, sz)范围中选择一个下标
        int index = rand() % sz;
        // 如果该下标原本存储的是黑名单的数字
        if (IndexToVal.count(index)) {
            // 返回该下标存储的数组
            return IndexToVal[index];
        }
        // 如果此时index对应的数字没有在黑名单中，直接返回即可
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

