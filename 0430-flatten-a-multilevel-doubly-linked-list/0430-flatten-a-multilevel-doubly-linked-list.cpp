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
        list<Node*> nextList;
        return helper(NULL,head, nextList);
    }

    Node* helper(Node* prev, Node* head, list<Node*>& nextList){

        if (head == NULL){
            return NULL;
        }

        head->prev = prev;

        if (head->child != NULL){
            nextList.push_front(head->next);
            head->next = helper(head, head->child, nextList);
            head->child = NULL;
            return head;
        } else if (head->next != NULL){
            head->next = helper(head, head->next, nextList);
            return head;
        } else {
            Node* next = NULL;
            if (nextList.size() != 0){
                next = nextList.front();
                nextList.pop_front();
            }

            head->next = helper(head, next, nextList);
            return head;
        }
    }
};