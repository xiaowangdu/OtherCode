class Solution {
public:
    /**
     * @param A: an integer array
     * @return: nothing
     */
     
    int partition(int start, int end, vector<int> &vc){
        int pivoit = vc[start];
        
        while(start < end){
            while(start < end && pivoit <= vc[end]) end--;
            vc[start] = vc[end];
            
            while(start < end && pivoit >= vc[start]) start++;
            vc[end] = vc[start]; 
        }
        
        vc[start] = pivoit;
        return start;
    }
     
    void quick_sort(int start, int end, vector<int> &vc){
        if(start >= end){
            return;
        }
        
        int cen = partition(start, end, vc);
        quick_sort(start, cen - 1, vc);
        quick_sort(cen + 1, end, vc);
        
    }
     
    void sortIntegers2(vector<int> &A) {
        // write your code here

        quick_sort(0, A.size() - 1, A);
    }
};