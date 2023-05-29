/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
class Solution {
public:
    vector<int> presum;
    Solution(vector<int>& w) {
        // 得到前缀和数组
        presum.resize(w.size()+1);
        presum[0] = 0;
        for (int i = 0; i < w.size(); i++) {
            presum[i+1] = presum[i]+w[i];
        }
    }
    
    int pickIndex() {
        int n = presum.size();
        // 得到在presum最大值范围内的随机数，不取0，所以结果要加一
        int target = (rand() % presum[n-1])+1;
        // 调用左侧二分查找算法得到大于等于target的下标
        // 注意这里的搜索范围为[1, presum_max]
        int left = 1, right = n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (presum[mid] < target) {
                left = mid+1;
            }
            else if (presum[mid] > target) {
                right = mid - 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left-1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

