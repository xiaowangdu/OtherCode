class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    /*
    int sumvector(vector<int> &vec){
        if(vec.size() <= 0){
            return INT_MIN;
        }
        
        int res = vec[0];
        for(int i = 1; i < vec.size(); ++i){
            res += vec[i];
        }
        
        return res;
    } 
    */
     
    void subcombination(vector<vector<int>> &res,  
                        vector<int> &lists, vector<int> &candidates, int pos, int target){
        if(target == 0){
            res.push_back(lists);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        for(int i = pos; i < candidates.size(); ++i){
            if(candidates[i] > target){
                continue;
            }
            
            lists.push_back(candidates[i]);
            subcombination(res, lists, candidates, i, target - candidates[i]);
            lists.pop_back();
        }
        
    }
     
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> lists;
        
        if(candidates.size() <= 0){
            return res;
        }
        
        sort(candidates.begin(), candidates.end());
        subcombination(res, lists, candidates, 0, target);
        
        return res;
    }
    
};