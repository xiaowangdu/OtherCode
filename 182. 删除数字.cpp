class Solution {
public:
    /**
     * @param A: A positive integer which has N digits, A is a string
     * @param k: Remove k digits
     * @return: A string
     */
     //删除一个数使剩余数最小的技巧
     
    string DeleteDigits(string &A, int k) {
        // write your code here
        if(A.length() <= 0){
            return "";
        }
        
        for(int i = k; i > 0; i--){
            int j = 0;
            for(; j + 1 < A.length(); j++){
                if(int(A[j]) > int(A[j + 1])){
                    break;
                }
            }
            
            A = A.erase(j, 1);
        }
        
        //"024" ==> "24"
        int i = 0;
        while(A[i++] == '0');
        
        return A.substr(i-1);
    }
};