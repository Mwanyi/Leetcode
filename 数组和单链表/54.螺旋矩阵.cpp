/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = n-1;
        int up = 0, down = m-1;
        while (result.size() < m*n) {
            if (up <= down) {
                for (int i = left; i <= right; i++) {
                    result.push_back(matrix[up][i]);
                }
                up++;
            }
            if (left <= right) {
                for (int i = up; i <= down; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[down][i]);
                }
                down--;
            }
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};
// @lc code=end

