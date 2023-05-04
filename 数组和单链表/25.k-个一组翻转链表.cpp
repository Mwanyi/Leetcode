/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    // 反转[head, tail)部分节点,迭代实现
    ListNode* Reverse(ListNode* head, ListNode* tail) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* last = cur->next;
        while (cur != tail) {
            last = cur->next;
            cur->next = pre;
            pre = cur;
            cur = last;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // 首先反转前k个节点
        ListNode* tail = head;
        for (int i = 0; i < k; i++) {
            // 剩余的长度小于k，则不反转直接返回
            if (!tail) return head;
            tail = tail->next;
        }
        ListNode* newhead = Reverse(head, tail);
        // 调用递归翻转后面的部分
        head->next = reverseKGroup(tail, k);
        return newhead;
    }
};
// @lc code=end

