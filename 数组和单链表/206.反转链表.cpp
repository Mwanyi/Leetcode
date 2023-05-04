/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
/*
    // 递归方法
    ListNode* reverseList(ListNode* head) {
        // 此时不需要反转，直接返回
        if (!head || !head->next) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        // 关键点，这里一定要将后面指向nullptr
        head->next = nullptr;
        return last;
    }
*/

    // 非递归方法
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* last = head->next;
        while (cur) {
            last = cur->next;
            cur->next = pre;
            pre = cur;
            cur = last;
        }
        return pre;
    }
/*
    // 反转链表的前N个节点,递归方法
    ListNode* tail = nullptr;
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            tail = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = tail;
        return last;
    }
*/

};
// @lc code=end

