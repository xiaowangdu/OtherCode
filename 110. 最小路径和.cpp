class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
        int M = grid.size();
        if(M <= 0){
            return 0;
        }
        int N = grid[0].size();
        
        vector<vector<int>> minPathSumPos;
        for(int i = 0; i < M; i++){
            vector<int> tmp(N, 0);
            minPathSumPos.push_back(tmp);
        }
        
        minPathSumPos[0][0] = grid[0][0];
        for(int i = 1; i < N; i++){
            minPathSumPos[0][i] = minPathSumPos[0][i - 1] + grid[0][i];
        }
        
        for(int i = 1; i < M; i++){
            minPathSumPos[i][0] = minPathSumPos[i - 1][0] + grid[i][0];
        }
        
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                minPathSumPos[i][j] = min(minPathSumPos[i - 1][j], minPathSumPos[i][j - 1]) + grid[i][j];
            }
        }
        
        return minPathSumPos[M - 1][N - 1];
    }
};