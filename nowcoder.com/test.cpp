#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int value){
        val = value;
        left = right = NULL;
    }
};

void recurvise(TreeNode *node){
    if(node == NULL){
        return;
    }
    
    recurvise(node->left);
    cout << node->val << endl;
    recurvise(node->right);
    
}



int main(){
    map<int, int> mp;
    
    vector<int> vc(3, 0);
    vector<int>::iterator iter = vc.begin();
    
    for(;iter != vc.end(); iter++){
        cout << *iter;
        mp[*iter] += 1;
    }
   
    map<int, int>::iterator it = mp.begin();
    while(it != mp.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }
    
    return 0;
}