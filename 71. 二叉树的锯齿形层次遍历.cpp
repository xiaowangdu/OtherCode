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
        vector<TreeNode *> tmp;
        vector<TreeNode *> tmp_next;
        
        if(root == NULL){
            return res;
        }

        TreeNode * p = root;
        tmp.insert(tmp.begin(), p);
        
        bool flag = true;
        do{
            for(int i = 0; i < tmp.size(); ++i){
                p = tmp[i];
                res_tmp.push_back(p->val);
                
                if(flag){
                    if(p->left)tmp_next.insert(tmp_next.begin(), p->left);
                    if(p->right)tmp_next.insert(tmp_next.begin(), p->right);               
                }
                else{
                    if(p->right)tmp_next.insert(tmp_next.begin(), p->right); 
                    if(p->left)tmp_next.insert(tmp_next.begin(), p->left);
                }
                
            }
            flag = !flag;
            tmp = tmp_next;
            tmp_next.clear();
            
            res.push_back(res_tmp);
            res_tmp.clear();
            
        }while(tmp.size() > 0);

    }
};