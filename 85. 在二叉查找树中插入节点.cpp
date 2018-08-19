/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        // write your code here
        if(root == NULL){
            root = node;
            return root;
        }
        
        TreeNode * p = root;
        TreeNode * parent = NULL;
        while(p != NULL){
            parent = p;
            if(p->val < node->val){
                p = p->right;
            }
            else{
                p = p->left;
            }
        }
        
        if(parent->val < node->val){
            parent->right = node;
        }
        else{
            parent->left = node;
        }
        
        return root;
    }
};