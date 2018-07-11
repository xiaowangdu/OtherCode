class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        // write your code here
        if(nums.size() <= 0){
            return 0;
        }
        
        vector<int> subsequencePos(nums.size(), 0);
        subsequencePos[0] = 1;
        
        int maximum = INT_MIN;
        for(int i = 1; i < nums.size(); i++){
            maximum = INT_MIN;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    maximum = max(subsequencePos[j], maximum);
                }
            }
            
            if(maximum != INT_MIN){
                subsequencePos[i] = maximum + 1;
            }
            else{
                subsequencePos[i] = 1;
            }
        }
        
        int res = INT_MIN;
        for(int i = 0; i < subsequencePos.size(); i++){
            res = max(res, subsequencePos[i]);
        }
        
        return res;
    }
};