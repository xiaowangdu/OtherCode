class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        if(m == 0 || n == 0){
            return 0;
        }
        
        vector<vector<int>> pathsPos;
        for(int i = 0; i < m; i++){
            vector<int> tmp(n, 1);
            pathsPos.push_back(tmp);
        }
        
        //for(int i = 1; i < n; i++) pathsPos[0][i] = 1;
        //for(int i = 1; i < m; i++) pathsPos[i][0] = 1;
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                pathsPos[i][j] = pathsPos[i - 1][j] + pathsPos[i][j - 1];
            }
        }
        
        return pathsPos[m - 1][n - 1];
    }
};