/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int result = 0;
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrace(board, 0);
        return result;
    }
    void backtrace(vector<string>& borad, int row) {
        // 与Ⅰ相比就只需要更改此部分，将结果加一即可
        if (row == borad.size()) {
            result++;
            return ;
        }
        int n = borad[row].size();
        for (int i = 0; i < n; i++) {
            if (!isvaild(borad, row, i)) {
                continue;
            }
            // 做选择
            borad[row][i] = 'Q';
            backtrace(borad, row+1);
            // 回溯
            borad[row][i] = '.';
        }
    }

    bool isvaild(vector<string>& board, int row, int col) {
        int n = board[row].size();
        // 当前行如果有棋子则不合法
        for (int i = 0; i < n; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        // 当前列如果有棋子不合法
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        // 判断左上角
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        // 判断右上角
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

