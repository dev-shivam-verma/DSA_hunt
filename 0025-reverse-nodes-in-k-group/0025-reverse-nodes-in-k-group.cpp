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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        ListNode* temp = head;
        int count = 1;

        // does have k nodes ahed? 
        while (temp->next != NULL && count < k){
            temp = temp->next;
            count++;
        }
        if (count < k) return head;

        temp = head;
        ListNode* prev = NULL;
        count = 0;
        // reversing k nodes
        while (count < k){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        // joining tail to head
        head->next = reverseKGroup(temp, k);


        return prev;
    }

   
};