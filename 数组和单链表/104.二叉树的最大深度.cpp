/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // // 最大深度
    // int result;
    // // 当前的深度
    // int depth;
    // int maxDepth(TreeNode* root) {
    //     // 遍历思想
    //     traverse(root);
    //     return result;
    // }
    // void traverse(TreeNode* root) {
    //     if (!root) {
    //         return ;
    //     }
    //     depth++;
    //     if (!root->left && !root->right) {
    //         result = max(result, depth);
    //     }
    //     traverse(root->left);
    //     traverse(root->right);
    //     depth--;
    // }

    int maxDepth(TreeNode* root) {
        // 分解思想
        if (!root) {
            return 0;
        }
        int depth;
        depth = max(maxDepth(root->left)+1, maxDepth(root->right)+1);
        return depth;
    }
};
// @lc code=end

