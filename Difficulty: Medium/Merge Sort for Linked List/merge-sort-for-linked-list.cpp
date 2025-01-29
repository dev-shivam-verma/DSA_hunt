//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if (head == NULL || head->next == NULL) return head;
        
        Node* slow = head;
        Node* fast = head;
        while (fast->next == NULL && fast->next->next == NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* secondHead = slow->next;
        slow->next = NULL;
        
        // left half
        Node* leftHead = mergeSort(head);
        // right half
        Node* rightHead = mergeSort(secondHead);
        
        
        head = merge(leftHead, rightHead);
        return head;
    }
    
    Node* merge(Node* leftHead, Node* rightHead){
        
        if (rightHead == NULL || leftHead == NULL){
            return rightHead == NULL ? leftHead : rightHead;
        }
        
        if (leftHead->data <= rightHead->data){
            leftHead->next = merge(leftHead->next, rightHead);
            return leftHead;
        } else {
            rightHead->next = merge(leftHead, rightHead->next);
            return rightHead;
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends