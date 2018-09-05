#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsets(vector<int> &list, vector<int> &A, int start, vector<vector<int>> &res){
    if(list.size() > 0){
        res.push_back(list);
    }
    
    if(start >= A.size()){
        return;
    }  
    
    for(int i = start; i < A.size(); i++){
        list.push_back(A[i]);
        subsets(list, A, i + 1, res);
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
    subsets(list, vc, 0, res);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
            
        cout << endl;
    }    
    
    return 0;
}
