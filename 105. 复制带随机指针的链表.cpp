/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 #include <map>
 
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(head == NULL){
            return NULL;
        }
        
        RandomListNode *p = head;
        map<RandomListNode *, RandomListNode *> table;
        while(p != NULL){
            RandomListNode *tmp = new RandomListNode(p->label);
            table[p] = tmp;
            
            p = p->next;
        }
        
        p = head;
        while(p != NULL){
            table[p]->next = table[p->next];
            table[p]->random = table[p->random];
            
            p = p->next;
        }
        
        return table[head];
    }
};