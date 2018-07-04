class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
     
    //不使用subvector有着鲜明的时间复杂度
    
    /* 
    int subvector(vector<int> &vec){
       int res = INT_MIN;
       if(vec.size() <= 0){
           return res;
       }
       
       res = vec[0];
       for(int i = 1; i < vec.size(); ++i){
           res += vec[i];
       }
       
       return res;
    }
    */
     
    void subcombination(vector<vector<int>> &res, vector<int> &lists, vector<int> &num, int pos, int target){
        if(target == 0){
            res.push_back(lists);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        
        for(int i = pos; i < num.size(); ++i){
            if(i != pos && num[i-1] == num[i]){
                continue;
            }
            
            lists.push_back(num[i]);
            subcombination(res, lists, num, i + 1, target - num[i]);
            lists.pop_back();
        }
        
    } 
     
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> lists;
        
        if(num.size() <= 0){
            return res;
        }
        
        sort(num.begin(), num.end());
        subcombination(res, lists, num, 0, target);
        
    }
};