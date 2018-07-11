class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n <= 0){
            return 0;
        }
        
        vector<int> numsPos(n + 1, 0);
        numsPos[0] = numsPos[1] = 1;
        
        for(int i = 2; i <= n; i++){
            numsPos[i] = numsPos[i - 1] + numsPos[i - 2];
        }
        
        return numsPos[n];
    }
};