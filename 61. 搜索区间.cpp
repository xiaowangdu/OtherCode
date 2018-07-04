class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        
        if(A.size() == 0){
            return res;
        }
        
        int start = 0;
        int end = A.size() - 1;
        int mid = 0;
     
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(target < A[mid]){
                end = mid;
            }
            else if(target > A[mid]){
                start = mid;
            }
            else{
                //find start index
                end = mid;
            }
        }
        
        if(target == A[start]){
            res[0] = start;
        }
        else if(target == A[end]){
            res[0] = end;
        }
        else{
            return res;
        }
        
        start = res[0];
        end = A.size() - 1;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(target < A[mid]){
                end = mid;
            }
            else if(target > A[mid]){
                start = mid;
            }
            else{
                //find end index
                start = mid;
            }
        }
        
        if(target == A[end]){
            res[1] = end;
        }
        else if(target == A[start]){
            res[1] = start;
        }
        else{
            return res;
        }
        
        return res;
    }
};