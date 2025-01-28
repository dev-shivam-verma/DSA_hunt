/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        while (curr != NULL){
            if (curr->child != NULL){
                Node* next = curr->next;
                
                //flatten the child 
                curr-> next = flatten(curr->child);
                curr->child = NULL;

                curr->next->prev = curr;

                while (curr->next != NULL){
                    curr = curr->next;
                }

                // linking the flatten list to next
                if (next != NULL){
                    next->prev = curr;
                    curr->next = next;
                }
            }

            curr = curr->next;
        }

        return head;
    }

    

};