class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
     
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
        if(A.size() <= 0 || B.size() <= 0){
            return 0;
        }
        
        vector<vector<int>> sequencesPos;
        int m = A.size(), n = B.size();
        for(int i = 0; i < m; i++){
            vector<int> tmp(n, 0);
            sequencesPos.push_back(tmp);
        }
        
        if(A[0] == B[0])
            sequencesPos[0][0] = 1;
        
        for(int j = 1; j < n; j++){
            sequencesPos[0][j] = sequencesPos[0][j - 1];
            if(A[0] == B[j] && sequencesPos[0][j] == 0){
                sequencesPos[0][j] = 1;
            }
        }
        
        for(int j = 1; j < m; j++){
            sequencesPos[j][0] = sequencesPos[j - 1][0];
            if(A[j] == B[0] && sequencesPos[j][0] == 0){
                sequencesPos[j][0] = 1;
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(A[i] == B[j]){
                    sequencesPos[i][j] = sequencesPos[i - 1][j - 1] + 1;
                }
                else{
                    sequencesPos[i][j] = max(sequencesPos[i - 1][j], sequencesPos[i][j - 1]);
                }
            }
        }
        
        return sequencesPos[m - 1][n - 1];
    }
};