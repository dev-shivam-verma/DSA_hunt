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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* small = headA;
        ListNode* large = headB;

        while (small != NULL && large != NULL){
            small = small->next;
            large = large->next;
        }
        if (small != NULL){
            large = small;
            small = headB;
        }

        int diff = 0;
        while (large != NULL){
            large = large->next;
            diff++;
        }

        if (small == headB){
            large = headA;
        } else {
            large = headB; 
            small = headA;
        }

        // cover diff
        while (diff > 0){
            large = large->next;
            diff--;
        }

        while (large != NULL && small != NULL){
            if (large == small) return large;

            large = large->next;
            small = small->next;
        }

        return NULL;        
    }
};