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
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        vector<int> res_tmp;
        if(root == NULL){
            return res;
        }

        TreeNode * p = NULL;
        TreeNode * endflag = NULL;
        deque<TreeNode *> q;
        
        q.push_back(root);
        q.push_back(endflag);
    
        bool flag = true;
        while(!q.empty()){
            if(flag){
                p = q.front();
                q.pop_front();                
            }
            else{
                p = q.back();
                q.pop_back(); 
            }
            
            if(p == endflag){
                res.push_back(res_tmp);
                res_tmp.clear();
                
                if(!q.empty()){
                    if(flag){
                        q.push_front(endflag);             
                    }
                    else{
                        q.push_back(endflag);
                    }

                    flag = !flag;
                }
            }
            else{
                res_tmp.push_back(p->val);
                if(flag){
                    if(p->left)q.push_back(p->left);
                    if(p->right)q.push_back(p->right);  
                }
                else{
                    if(p->right)q.push_front(p->right); 
                    if(p->left)q.push_front(p->left);    

                } 
                
            }
        }
    }
};