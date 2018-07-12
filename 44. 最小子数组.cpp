class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 0){
            return INT_MAX;
        }
        
        vector<int> minsPos(nums.size(), INT_MAX);
        minsPos[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int mini = INT_MAX;
            for(int j = 0; j < i; j++){
                mini = min(mini, minsPos[i - 1]);
            }
            
            minsPos[i] = min(mini + nums[i], nums[i]);
        }
        
        int res = INT_MAX;
        for(int i = 0; i < minsPos.size(); i++){
            res = min(res, minsPos[i]);
        }
        
        return res;
    }
};