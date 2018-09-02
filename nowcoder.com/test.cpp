#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool static cmp(const int &a, const int &b){
    return a < b;
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

    sort(vc.begin(), vc.end(), cmp);

    for(int i = 0; i < vc.size(); i++){
        cout << vc[i] << " ";
    }    
    
    return 0;
}
