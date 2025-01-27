/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(head->val);
        Node* ogTemp = head->next;
        Node* newTemp = newHead;

        while (ogTemp != NULL){
            Node* copy = new Node(ogTemp->val);
            newTemp->next = copy;
            newTemp = newTemp->next;
            ogTemp = ogTemp->next;
        }

        unordered_map<Node*,Node*> m;

        ogTemp = head;
        newTemp = newHead;

        while (ogTemp != NULL){
            m[ogTemp] = newTemp;

            newTemp = newTemp->next;
            ogTemp = ogTemp->next;
        }

        ogTemp = head;
        newTemp = newHead;
        while (ogTemp != NULL){
            if (ogTemp->random != NULL){
                newTemp->random = m[ogTemp->random];
            }

            newTemp = newTemp->next;
            ogTemp = ogTemp->next;
        }
        return newHead;
    }
};