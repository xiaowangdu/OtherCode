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
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        if(head == NULL){
            return NULL;
        }
        
        ListNode leftdummy(0);
        leftdummy.next = head;
        
        ListNode rightdummy(0);
        rightdummy.next = head;
        
        ListNode *left = &leftdummy;
        ListNode *right = &rightdummy;

        while(head != NULL){
            if(head->val < x){
                left->next = head;
                left = head;

            }
            else{
                right->next = head;
                right = head;
            }
        
            head = head->next;
        }
        
        right->next = NULL;
        left->next = rightdummy.next;
        
        return leftdummy.next;
    }
};