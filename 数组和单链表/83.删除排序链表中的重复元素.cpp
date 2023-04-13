/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        ListNode* find = head->next;
        while (find) {
            if (find->val == cur->val) {
                find = find->next;
            }
            else {
                cur->next = find;
                cur = cur->next;
                find = find->next;
            }
        }
        // 关键点，如果后面都是重复的也需要消除
        cur->next = find;
        return head;
    }
};
// @lc code=end

