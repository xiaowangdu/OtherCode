#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool contain(vector<int> &list, int target){
    for(int i = 0; i < list.size(); i++){
        if(target == list[i]) return true;
    }
    
    return false;
}

void permutation(vector<int> &list, vector<int> &A, vector<vector<int>> &res){
    if(list.size() == A.size()){
        res.push_back(list);
        return;
    }
    
    for(int i = 0; i < A.size(); i++){
        if(contain(list, A[i])){
            continue;
        }
        
        list.push_back(A[i]);
        permutation(list, A, res);
        list.pop_back();
    }
}
  
int main()  
{  
    vector<int> vc;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        vc.push_back(x);
    } 

    vector<int> list;
    vector<vector<int>> res;
    permutation(list, vc, res);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
            
        cout << endl;
    }    
    
    return 0;
}
