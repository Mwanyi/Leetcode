/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // 先把字符串转化为对应的数字数组
        vector<int> nums(s.size());
        for (int i = 0; i < nums.size(); i++) {
            switch (s[i])
            {
            case 'A':
                nums[i] = 0;
                break;
            case 'C':
                nums[i] = 1;
                break;
            case 'G':
                nums[i] = 2;
                break;
            case 'T':
                nums[i] = 3;
                break;
            default:
                break;
            }
        }
        // 滑动窗口技巧
        // 存储遍历到的字符转化为数字的数组
        unordered_set<int> seed;
        // 保存最终结果，不保存重复
        unordered_set<string> res;
        int L = 10;
        int R = 4;
        int RL = pow(R, L-1);
        int windowhash = 0;

        int left = 0, right = 0;
        while (right < nums.size()) {
            int num = nums[right++];
            windowhash = windowhash*R+num;

            while (left < right && right-left == L) {
                if (seed.count(windowhash)) {
                    res.insert(s.substr(left, L));
                }
                else {
                    seed.insert(windowhash);
                }
                // 左移
                int denum = nums[left++];
                windowhash = windowhash - denum*RL;
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
// @lc code=end

