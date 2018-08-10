/**
 * 1、找到中点，同时对前半段旋转
 * 2、然后从中点向两边比较
 * 3、满足O(n), O(1)
 */

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
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        if(head == NULL){
            return true;
        }
    
        ListNode dummy(0);
        dummy.next = head;
        
        
        ListNode *fast = &dummy;
        ListNode *preslow = NULL;
        ListNode *slow = &dummy;
        ListNode *nexslow = slow->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            else{
                slow->next = preslow;
                preslow = slow;
                break;
            }
            
            ListNode *tmp = slow->next;
            
            slow->next = preslow;
            
            preslow = slow;
            slow = tmp;
            nexslow = slow->next;

        }
        
        while(nexslow != NULL && preslow != NULL){
            if(nexslow->val != preslow->val){
                return false;
            }
            
            nexslow = nexslow->next;
            preslow = preslow->next;
        }
        
        
        return true;
    }
};