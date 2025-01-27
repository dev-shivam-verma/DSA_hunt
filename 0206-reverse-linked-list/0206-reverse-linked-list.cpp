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
    ListNode* reverseList(ListNode* head) {
        ListNode* last = head;

        while (last != nullptr && last->next != nullptr) last = last->next;
        reverseRef(head);
        if (head != nullptr) head->next = nullptr;

        return last;        
    }

    ListNode* reverseRef(ListNode* node){
        if(node == nullptr || node->next == nullptr) return node;

        ListNode* next = reverseRef(node->next);
        next->next = node;

        return node;
    }
};