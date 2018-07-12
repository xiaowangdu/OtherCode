class Solution {
public:
    /*
     * @param : A string
     * @param : A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string S, string T) {
        // write your code here
        S = S.substr(1, S.size() - 2);
        T = T.substr(1, T.size() - 2);

        if(S.size() <= 0 || T.size() <= 0){
            return 1;
        }
        
        int M = T.size(), N = S.size();
        vector<vector<int>> disNumsPos;
        for(int i = 0; i < M; i++){
            vector<int> tmp(N, 0);
            disNumsPos.push_back(tmp);
        }
        
        if(T[0] == S[0]) disNumsPos[0][0] = 1;
        for(int i = 1; i < N; i++){
            if(T[0] == S[i]){
                disNumsPos[0][i] = disNumsPos[0][i - 1] + 1;
            }
            else{
                disNumsPos[0][i] = disNumsPos[0][i - 1];
            }
        }

        
        for(int i = 1; i < M; i++){
            for(int j = i; j < N; j++){
                if(T[i] != S[j]){
                    disNumsPos[i][j] = disNumsPos[i][j - 1];
                }
                else{
                    disNumsPos[i][j] = disNumsPos[i][j - 1] + disNumsPos[i - 1][j - 1];
                }
            }
        }
        
        return disNumsPos[M - 1][N - 1];
    }
};