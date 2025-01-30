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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        int count = 0;
        while (temp != NULL){
            temp = temp->next;
            count++;
        }

        int simpleK = k % count;
        for (int i = 0; i < simpleK; i++){
            head = rotate(head);
        }
        return head;
    }

    ListNode* rotate(ListNode* head){
        if (head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        temp->next = head;
        return temp;
    }
};