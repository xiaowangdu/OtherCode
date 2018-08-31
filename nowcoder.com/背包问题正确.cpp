#include <iostream>
#include <vector>

using namespace std;

int maxvalues(int maxv, vector<int> &volums, vector<int> &values) {

    int n = volums.size();
    if(n <= 0){
        return 0;
    }
    
    vector<vector<int>> maxPos(n, vector<int>(maxv+1, 0));

    for(int j = 1; j < maxv+1; j++){
        if(volums[0] <= j){
            maxPos[0][j] = values[0];
        }  
        else{
            maxPos[0][j] = 0;
        }
        //cout << maxPos[0][j] << " ";
    }
    //cout << endl;
    
    for(int i = 1; i < n; i++){
        for(int j = 1; j < maxv + 1; j++){
            if(volums[i] <= j){
                maxPos[i][j] = max(values[i] + maxPos[i - 1][j - volums[i]], maxPos[i - 1][j]);
            }    
            else{
                maxPos[i][j] = maxPos[i - 1][j];
            }
            //cout << maxPos[i][j] << " ";
        }
        //cout << endl;
    }
    
    return maxPos[n - 1][maxv];
}


int main(){
    int N, V;
    cin >> N >> V;
    
    vector<int> volums;
    vector<int> values;
    
    for(int i = 0; i < N; i++){
        int M1; cin >> M1;
        volums.push_back(M1);
        
        int M2; cin >> M2;
        values.push_back(M2);
    }
    
    cout << maxvalues(V, volums, values) << endl;
    
    return 0;
}