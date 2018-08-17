//https://segmentfault.com/a/1190000006325321

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
     
    int backPackRecursive(int k, int m, vector<int> &A, vector<vector<int>> &res){
        //cout << k << " " << m << endl;
        if(res[k][m] < 0){
            if(m+1 < A[k]){
                res[k][m] = backPackRecursive(k - 1, m, A, res);
            }
            else{
                res[k][m] = max(backPackRecursive(k - 1, m, A, res), A[k] + backPackRecursive(k - 1, m  - A[k], A, res));
            }
            
        }

        return res[k][m];
    }
     
    int backPack(int m, vector<int> &A) {
        // write your code here
        
        int n = A.size();
        if(n <= 0){
            return 0;
        }
        

        vector<vector<int>> maxPos(n, vector<int>(m, -1));

        for(int j = 0; j < m; j++){
            if(A[0] <= j+1){
                maxPos[0][j] = A[0];
            }  
            else{
                maxPos[0][j] = 0;
            }
        }
#if 0
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(A[i] <= j+1){
                    maxPos[i][j] = max(A[i] + maxPos[i - 1][j - A[i]], maxPos[i - 1][j]);
                }    
                else{
                    maxPos[i][j] = maxPos[i - 1][j];
                }
            }
        }
#else
        return backPackRecursive(n - 1, m - 1, A, maxPos);
#endif
    
        
        return maxPos[n - 1][m - 1];
    }
};