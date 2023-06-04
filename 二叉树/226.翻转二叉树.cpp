/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        // // 遍历解法
        // traverse(root);
        // return root;

        // 分解解法
        if (root == nullptr) return nullptr;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    void traverse(TreeNode* root) {
        // 如果为空直接返回
        if (!root) {
            return ;
        }
        traverse(root->left);
        traverse(root->right);
        // 后序位置进行交换
        TreeNode* ret = root->left;
        root->left = root->right;
        root->right = ret;
    }
};
// @lc code=end

