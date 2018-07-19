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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<int> tmp;
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        
        TreeNode *pscan = NULL;
        TreeNode *endflag = NULL;
        queue<TreeNode *> q;
        
        q.push(root);
        q.push(endflag);
        
        while(!q.empty()){
            pscan = q.front();
            q.pop();

            if( pscan == endflag){
                res.push_back(tmp);
                tmp.clear();
                
                if(!q.empty()){
                    q.push(endflag);
                }
            }
            else{
                tmp.push_back(pscan->val);
                if(pscan->left)q.push(pscan->left);
                if(pscan->right)q.push(pscan->right);
            }
        }
        
        return res;
    }
};