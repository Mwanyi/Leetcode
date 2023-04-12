/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lesshead = new ListNode();
        ListNode* greaterhead = new ListNode();
        ListNode* lesscur = lesshead;
        ListNode* gcur = greaterhead;
        ListNode* cur = head;
        while (cur) {
            if (cur->val < x) {
                lesscur->next = cur;
                lesscur = lesscur->next;
            }
            else {
                gcur->next = cur;
                gcur = gcur->next;
            }
            // 关键部分，要将原本的cur结点设为空
            ListNode* ret = cur->next;
            cur->next = nullptr;
            cur = ret;
        }
        lesscur->next = greaterhead->next;
        return lesshead->next;
    }
};
// @lc code=end

