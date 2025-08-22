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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return f(0, l1, l2);
    }

    ListNode f(int carry, ListNode nodeA, ListNode nodeB) {
        if (nodeA == null && nodeB == null) {
            if (carry == 0) return null;
            else return new ListNode(carry);
        }

        int sum = carry;
        ListNode nextA = null;
        ListNode nextB = null;

        if (nodeA != null){
            sum += nodeA.val;
            nextA = nodeA.next;
        } 

        if (nodeB != null) {
            sum += nodeB.val;
            nextB = nodeB.next;
        }

        int val = sum % 10;
        carry = sum / 10;

        ListNode resultNode = new ListNode(val);
        resultNode.next = f(carry, nextA, nextB);

        return resultNode;
    }
}