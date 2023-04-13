/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        // 使用优先队列（实际实现方式是小堆）
        std::priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> priq([](ListNode* a, ListNode* b){
            return a->val > b->val;
        });
        for (int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            if (head) {
                priq.push(head);
            }
        }
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (!priq.empty()) {
            ListNode* node = priq.top();
            priq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) {
                priq.push(node->next);
            }
        }
        return head->next;
    }
};
// 时间复杂度：设链条个数为k，一共有n个结点，O(n*logk)
// @lc code=end

