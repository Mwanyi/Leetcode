/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> dp;
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (dp.count(root) > 0) {
            return dp[root];
        }
        // 抢占该位置，走到下下个
        int result1 = root->val+ (root->left == nullptr ?
                       0 : rob(root->left->left) + rob(root->left->right))
                    + (root->right == nullptr ?
                       0 : rob(root->right->left) + rob(root->right->right));
        // 不抢占该位置，走到下一个
        int result2 = rob(root->left)+rob(root->right);
        int res = max(result1, result2);
        dp[root] = res;
        return res;
    }
};
// @lc code=end

