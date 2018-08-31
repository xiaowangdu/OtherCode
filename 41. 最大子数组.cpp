class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
     
     //1、dp maxsPos[i] 前i+1个数中以nums[i]结尾的最大子数组
     //2、贪心算法
     
    int maxSubArray(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 0){
            return INT_MIN;
        }
        /*
        vector<int> maxsPos(nums.size(), INT_MIN);
        maxsPos[0] = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            maxsPos[i] = max(maxsPos[i - 1] + nums[i], nums[i]);
        }
        
        int res = INT_MIN;
        for(int i = 0; i < maxsPos.size(); i++){
            res = max(res, maxsPos[i]);
        }*/
        
        
        int res = nums[0], tmpsum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(tmpsum > 0){
                tmpsum += nums[i];
                
            }
            else{
                tmpsum = nums[i];
            }
            
            res = max(res, tmpsum);
            
        }
        
        return res;
    }
};