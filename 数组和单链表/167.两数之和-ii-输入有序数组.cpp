/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int left = 0, right = numbers.size()-1;
        while (left < right) {
            if (numbers[left]+numbers[right] == target) {
                result.push_back(left+1);
                result.push_back(right+1);
                break;
            }
            else if(numbers[left]+numbers[right] < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return result;
    }
};
// @lc code=end

