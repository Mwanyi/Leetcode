/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        // 方法一：反转链表并判断
        // // 方法二：后序位置判断
        // left = head;
        // return traverse(head);
        // 方法三：方法二空间优化
        // 1.快慢指针找到中间结点
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 奇数长度的起始点在中间结点的后面
        if (fast) {
            slow = slow->next;
        }
        // 2.反转slow之后的链表
        ListNode* right = reverse(slow);
        // 3.对比
        left = head;
        while (right && left)
        {
            if (right->val != left->val) {
                return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    bool traverse(ListNode* right) {
        if (!right) return true;
        bool res = traverse(right->next);
        // 后续位置
        res = res && (left->val == right->val);
        left = left->next;
        return res;
    }
};
// @lc code=end

