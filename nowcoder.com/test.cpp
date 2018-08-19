#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> vc(5, 0);
    vector<int>::iterator iter = vc.begin();
    
    for(;iter != vc.end(); iter++){
        cout << *iter;
        
    }
   
    
    return 0;
}