/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here
        if(head == NULL){
            return head;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *preDeleteNode = &dummy;
        int i = 0;
        while(head != NULL){
            i++;
            head = head->next;
            if(i > n){
                preDeleteNode = preDeleteNode->next;
            }
        }
        
        //delete end node
        ListNode *p = preDeleteNode->next;
        preDeleteNode->next = p->next;
        delete p;
        
        return dummy.next;
    }
};