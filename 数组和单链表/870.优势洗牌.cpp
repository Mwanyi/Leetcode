/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
class Solution {
public:
    struct num {
        int index;
        int val;
        num(int _index, int _val) {
            index = _index;
            val = _val;
        }
        // 默认降序，堆使用小根堆，因此重载<
        bool operator < (const num& n) const{
            return val < n.val;
        }
    };
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> result(n);
        // 使用优先队列对nums2进行排序,默认降序
        priority_queue<num> maxnums2;
        for (int i = 0; i < n; i++) {
            maxnums2.push(num(i, nums2[i]));
        }
        // 对nums1进行排序
        std::sort(nums1.begin(), nums1.end());
        // 使用双指针得到最小值和最大值
        int left = 0, right = n-1;
        while (!maxnums2.empty()) {
            if (maxnums2.top().val < nums1[right]) {
                result[maxnums2.top().index] = nums1[right];
                right--;
            }
            else {
                result[maxnums2.top().index] = nums1[left];
                left++;
            }
            maxnums2.pop();
        }
        return result;
    }
};


// @lc code=end

