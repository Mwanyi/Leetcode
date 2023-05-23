/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 先经过对角线进行从行到列的转化
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int ret = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = ret;
            }
        }
        // 再进行水平翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n/2; j++) {
                int ret = matrix[i][j];
                matrix[i][j] = matrix[i][n-1-j];
                matrix[i][n-1-j] = ret;
            }
        }
    }
};
// @lc code=end

