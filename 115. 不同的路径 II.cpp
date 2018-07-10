class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // write your code here
        if(obstacleGrid.size() <= 0){
            return 0;
        }
        
        vector<vector<int>> pathsPos;
        for(int i = 0; i < obstacleGrid.size(); i++){
            vector<int> tmp(obstacleGrid[0].size(), 1);
            pathsPos.push_back(tmp);
        }
        
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        for(int i = 1; i < obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i] == 1) {
                pathsPos[0][i] = 0;
            }
            else{
                pathsPos[0][i] = pathsPos[0][i - 1];
            }
        }
        
        for(int i = 1; i < obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1) {
                pathsPos[i][0] = 0;
            }
            else{
                pathsPos[i][0] = pathsPos[i - 1][0];
            }
        }
        
        for(int i = 1; i < obstacleGrid.size(); i++){
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 1){
                    pathsPos[i][j] = 0;
                }
                else{
                    pathsPos[i][j] = pathsPos[i - 1][j] + pathsPos[i][j - 1];
                }
            }
        }
        
        return pathsPos[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};