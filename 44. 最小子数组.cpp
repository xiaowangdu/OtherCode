class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
     //1、dp maxsPos[i] 前i+1个数中以nums[i]结尾的最小子数组
     //2、贪心算法
     
    int minSubArray(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 0){
            return INT_MAX;
        }
        
        //1、dp
        /*
        vector<int> minsPos(nums.size(), INT_MAX);
        minsPos[0] = nums[0];
        int res = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            minsPos[i] = min(minsPos[i - 1] + nums[i], nums[i]);
            res = min(res, minsPos[i]);
        }*/

        //2、贪心算法
        int res = nums[0], tmpsum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(tmpsum < 0){
                tmpsum += nums[i];
            }
            else{
                tmpsum = nums[i];
            }
            
            res = min(tmpsum, res);
        }
 
        return res;
    }
};