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
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    void recurvise(TreeNode *node, int &k, int &res){
        if(node == NULL){
            return;
        }
        
        recurvise(node->left, k, res);
        if(k > 0){
            k--;
            if(k == 0) res = node->val;
        }
        recurvise(node->right, k, res);
        
    }
     
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        int res = 0;
        recurvise(root, k, res);
        
        return res;
    }
};