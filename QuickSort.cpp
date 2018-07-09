#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector<int> &arr, int left, int right)
{
    if(left >= right){
        return;
    }

    int pivot = arr[left];
    int i = left;
    int j = right;

    while(i < j){
        while(i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];

        while(i < j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }

    arr[i] = pivot;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

int main() 
{
    int arr[4] = {3, 4, 1, 6};
    vector<int> vc(arr, arr + 4);
    
    quicksort(vc, 0, 3);
    
    for(int i = 0; i < vc.size(); i++){
        
        cout  << vc[i] << endl;
    }
	

	return 0;
}