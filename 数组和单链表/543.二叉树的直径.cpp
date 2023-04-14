/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int result;
    int diameterOfBinaryTree(TreeNode* root) {
        // 需要考虑子树而获得信息，因此为后序位置
        Maxdia(root);
        return result;
    }
    int Maxdia(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftdia = Maxdia(root->left);
        int rightdia = Maxdia(root->right);
        result = max(leftdia+rightdia, result);
        return max(leftdia, rightdia)+1;
    }
};
// @lc code=end

