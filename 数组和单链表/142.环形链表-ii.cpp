/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            if (fast == slow) {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast || !fast->next) {
            return nullptr;
        }
        fast = fast->next;
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

