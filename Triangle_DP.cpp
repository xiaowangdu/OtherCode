/*
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
*/

/*
11
21 22
31 32 33
41 42 43 44
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define MAX_INT numeric_limits<int>::max()

int minSum(vector<vector<int> > &arr, vector<vector<int> > &minSumPos)
{
    if(arr.size() <= 0){
        return MAX_INT;
    }
    
    for(int i = 0; i < arr[arr.size() - 1].size(); i++){
        minSumPos[arr.size() - 1][i] = arr[arr.size() - 1][i];
    }
    
    for(int i = arr.size() - 2; i >= 0; i--){
        for(int j = 0; j < arr[i].size(); j++){
            minSumPos[i][j] = min(minSumPos[i + 1][j], minSumPos[i + 1][j + 1]) + arr[i][j];
        }
    }
    
    /*
    if(x >= arr.size()){
        return 0;
    }
    
    if(minSumPos[x][y] == MAX_INT){
        minSumPos[x][y] = min(minSum(arr, minSumPos, x + 1, y), minSum(arr, minSumPos, x + 1, y + 1)) + arr[x][y];
    }*/
    
    return minSumPos[0][0];
}

int main()
{
    int row1[] = {2};
    int row2[] = {3, 4};
    int row3[] = {6, 5, 7};
    int row4[] = {4, 1, 8, 3};
    
    int *rows[4] = {row1, row2, row3, row4};
    vector<vector<int> > array;
    vector<vector<int> > minSumPos;
    
    for(int i = 0; i < 4; i++){
        vector<int> tmp(rows[i], rows[i] + (i + 1));
        array.push_back(tmp);
        
        vector<int> minSumPostmp(i+ 1, MAX_INT);
        minSumPos.push_back(minSumPostmp);
    }
    
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array[i].size(); j++){
            cout << array[i][j] << ",";
        }
        cout << endl;
    }
    
    cout << "==================Result==================" << endl;
    cout << minSum(array, minSumPos) << endl;
    
    return 0;
}


