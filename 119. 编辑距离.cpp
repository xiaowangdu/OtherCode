class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        // write your code here
        cout << word1 << endl;
        cout << word2 << endl;
        if(word1.size() <= 0 && word2.size() <= 0){
            return 0;
        }
        
        if(word1.size() <= 0 && word2.size() > 0){
            return word2.size();
        }
        if(word1.size() > 0 && word2.size() <= 0){
            return word1.size();
        }
        
        vector<vector<int>> distancesPos;
        int M = word1.size(), N = word2.size();
        for(int i = 0; i < M; i++){
            vector<int> tmp(N, 0);
            distancesPos.push_back(tmp);
        }
        
        if(word1[0] != word2[0]){
            distancesPos[0][0] = 1;
        }
        int flag = distancesPos[0][0];
        for(int i = 1; i < N; i++){
            if(word1[0] == word2[i] && flag == 1){
                distancesPos[0][i] = distancesPos[0][i - 1];
                flag = 0;
            }
            else{
                distancesPos[0][i] = distancesPos[0][i - 1] + 1;
            }
        }
        flag = distancesPos[0][0];
        for(int i = 1; i < M; i++){
            if(word1[i] == word2[0] && flag == 1){
                distancesPos[i][0] = distancesPos[i - 1][0];
                flag = 0;
            }
            else{
                distancesPos[i][0] = distancesPos[i - 1][0] + 1;
            }
        }
        
        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                int mini = min(distancesPos[i][j - 1], distancesPos[i - 1][j]);
                if(word1[i] == word2[j]){
                    distancesPos[i][j] = min(mini + 1, distancesPos[i - 1][j - 1]);
                }
                else{
                    distancesPos[i][j] = min(mini, distancesPos[i - 1][j - 1]) + 1;
                }
            }
        }
        
        return distancesPos[M - 1][N - 1];
    }
};