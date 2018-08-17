#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &src, int start, int mid, int end, vector<int> &temp){
    int left = start, right = mid + 1;
    
    int p = 0;
    while(left <= mid && right <= end){
        if(src[left] <= src[right]){
            temp[p++] = src[left++];
        }
        else{
            temp[p++] = src[right++];
        }
    }
    
    while(left <= mid){
        temp[p++] = src[left++];
    }
    
    while(right <= end){
        temp[p++] = src[right++];
    }
    
    for(int i = 0; i < p; i++){
        src[start + i] = temp[i];
    }
}

void mergesort(vector<int> &src, vector<int> &temp, int start, int end){
    if(start >= end){
        return;
    }
    
    int mid = start + (end - start)/2;
    mergesort(src, temp, start, mid);
    mergesort(src, temp, mid + 1, end);
    
    merge(src, start, mid, end, temp);
    
}

int main(){
    int n, x;
    vector<int> vc;
   
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        vc.push_back(x);
    }
    
    vector<int> temp(vc.size());
    mergesort(vc, temp, 0, vc.size() - 1);
    
    for(int i = 0; i < vc.size(); i++){
        cout << vc[i] << " ";
    }
    cout << endl;
    
    return 0;
}
