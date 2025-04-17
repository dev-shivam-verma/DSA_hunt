/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode head = popSmallest(lists);
        ListNode temp = head;

        while (temp != null){
            ListNode temp2 = popSmallest(lists);
            temp.next = temp2;
            temp = temp2;
        }

        return head;
    }

    private ListNode popSmallest(ListNode[] lists){
        int n = lists.length;
        int i = 0;
        while (i < n && lists[i] == null) i++;
        if (i == n) return null;
        
        for (int j = i; j < n; j++){
            if (lists[j] == null) continue;
            if (lists[i].val > lists[j].val) i = j;
        }

        ListNode temp = lists[i];
        lists[i] = lists[i].next;
        
        return temp;
    }
}