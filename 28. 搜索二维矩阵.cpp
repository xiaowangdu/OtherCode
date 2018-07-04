class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        
        int rows = matrix.size();
        if(rows == 0){
            return false;
        }
        
        int cols = matrix[0].size();
        //col_1 orient search
        int start = 0;
        int end = rows - 1;
        int mid = 0;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(target < matrix[mid][0]){
                end = mid;
            }
            else if(target > matrix[mid][0]){
                start = mid;
            }
            else{
                return true;
            }
        }
        
        int search_row = 0;
        if(target >= matrix[start][0] && target <= matrix[start][cols - 1]){
            search_row = start;
        }
        else if(target >= matrix[end][0] && target <= matrix[end][cols - 1]){
            search_row = end;
        }
        else{
            return false;
        }
        
        //row orient search
        start = 0;
        end = cols - 1;
        mid = 0;
        while(start + 1 < end){
            mid = start + (end - start)/2;
            if(target < matrix[search_row][mid]){
                end = mid;
            }
            else if(target > matrix[search_row][mid]){
                start = mid;
            }
            else{
                //return true;
                end = mid;
            }
        }
        
        if(target == matrix[search_row][start] || target == matrix[search_row][end]){
            return true;
        }
        
        return false;
    }
};