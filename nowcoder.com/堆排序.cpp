#if 0

#include <iostream>
#include <vector>

using namespace std;

void top2down(vector<int> &vc, int start, int end){
    int i = start, tmp, child = 0;
    
    for(tmp = vc[i]; 2*i + 1 < end; i = child){
        
        child = 2*i + 1;
        if(child + 1 < end && vc[child + 1] > vc[child]){
            child ++;
        }
        
        if(tmp < vc[child]){
            vc[i] = vc[child];
        }
        else{
            break;
        }
    }
}

void create(vector<int> &vc){
    for(int i = vc.size() / 2; i >= 0; i--){
        top2down(vc, i, vc.size());
    } 
}
    
void heapsort(vector<int> &vc){
    for(int i = vc.size() - 1; i > 0; i--){
        int tmp = vc[0];
        vc[0] = vc[i];
        vc[i] = tmp;
        top2down(vc, 0, i);
    }
}

int main(){
    vector<int> vc;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int x; scanf("%d", &x);
        vc.push_back(x);
    }
    
    create(vc);
    heapsort(vc);
    
    for(int i = 0; i < vc.size(); i++){
        cout << vc[i] << " ";
    }
    cout << endl;
    return 0;
}

#else

#include <string>  
#include <map>  
#include <iostream>  
#include <vector>  
using namespace std; 

void top2down(vector<int> &vc, int start, int size){
    int i = start, tmp, child;
    
    for(tmp = vc[i]; 2*i + 1 < size;){
        
        child = 2*i + 1;
        if(child + 1 < size && vc[child + 1] > vc[child]){
            child ++;
        }
        
        if(tmp < vc[child]){
            vc[i] = vc[child];
        }
        else{
            break;
        }
        
        i = child;
    }
      
    vc[i] = tmp; 
} 
  
void create(vector<int> &vc){
    for(int i = (vc.size() - 1) / 2; i >= 0; i--){
        top2down(vc, i, vc.size());
    } 
}
    
void heapsort(vector<int> &vc){
    for(int i = vc.size() - 1; i > 0; i--){
        int tmp = vc[0];
        vc[0] = vc[i];
        vc[i] = tmp;
        
        //最后一位不调整
        top2down(vc, 0, i);
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

    create(vc);
    heapsort(vc);

    for(int i = 0; i < vc.size(); i++){
        cout << vc[i] << " ";
    }    
    
    return 0;
}

#endif