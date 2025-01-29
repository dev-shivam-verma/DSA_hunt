//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        if (head == NULL) return head;
        Node* revHead = reverse(head);
        
        int carry = -1;
        Node* temp = revHead;
        
        while (temp != NULL){
            if (carry == -1){
                temp->data += 1;
            } else {
                temp->data += carry;
            }
            
            carry = temp->data/10;
            temp->data = temp->data % 10;
            
            temp = temp->next;
        }
        
        reverse(revHead);
        if (carry > 0){
            Node* newDigit = new Node(carry);
            newDigit->next = head;
            return newDigit;
        }
        
        return head;
    }
    
    Node* reverse(Node* head){
        Node* temp = head;
        Node* prev = NULL;
        
        while (temp != NULL){
            Node* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        
        return prev;
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
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends