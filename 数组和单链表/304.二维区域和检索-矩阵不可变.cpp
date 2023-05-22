/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> map;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        map = vector<vector<int>>(row+1, vector<int>(col+1));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                map[i][j] = map[i][j-1]+map[i-1][j]-map[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return map[row2+1][col2+1]-map[row2+1][col1]-map[row1][col2+1]+map[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

