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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> toRemoved = new HashSet<Integer>(); 

        for (int i: nums) toRemoved.add(i);

        while (toRemoved.contains(head.val)) head = head.next;
            

        ListNode temp = head; 
        while (temp != null && temp.next != null  ) {
            while (temp.next != null && toRemoved.contains(temp.next.val)) {
                temp.next = temp.next.next;
            }

            temp = temp.next;
        }

        return head;
    }
}