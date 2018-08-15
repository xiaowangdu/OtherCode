#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>

using namespace std;

#define MAX_INT numeric_limits<long long>::max()
#define MIN_INT numeric_limits<long long>::min()

long long maxMultiple(vector<int> &vc, int K, int d){
    if(vc.size() <= 0){
        return 0;
    }
    if(K > vc.size()){
        return 0;
    }
    
    long long maxValPos[10][50];
    long long minValPos[10][50];
    for(int i = 0; i < K; i++){
        for(int j = 0; j < vc.size(); j++){
            maxValPos[i][j] = minValPos[i][j] = 0;
        }
    }
    
    for(int i = 0; i < vc.size(); i++){
        maxValPos[0][i] = vc[i];
        minValPos[0][i] = vc[i];
    }
     
    for(int i = 1; i < vc.size(); i++){
        for(int k = 1; k < K; k++){
            for(int s = i - 1; s >= 0 && (i-s) <= d; s--){
                maxValPos[k][i] = max(maxValPos[k][i], max(vc[i]*maxValPos[k-1][s], vc[i]*minValPos[k-1][s]));
                minValPos[k][i] = min(minValPos[k][i], min(vc[i]*maxValPos[k-1][s], vc[i]*minValPos[k-1][s]));
            }
        }
    }
    
    long long res = MIN_INT;
    for(int i = 0; i < vc.size(); i++){
        res = max(res, maxValPos[K-1][i]);
    }
    
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> vc;
    
    for(int i = 0; i < n; i++){
        int x; scanf("%d", &x);
        vc.push_back(x);
    }
    
    int k, d;
    cin >> k >> d;

    cout << maxMultiple(vc, k, d) << endl;
    
    return 0;
}