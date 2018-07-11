class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    
    int string2Num(string &s, int pos, int n){
        if(pos + n > s.length()){
            return INT_MAX;
        }
        
        return atoi(s.substr(pos, n).c_str());
    }
     
    int numDecodings(string &s) {
        // write your code here
        if(s.length() <= 0){
            return 0;
        }
        
        vector<int> numDecodingsPos(s.length(), 0);
        
        if(s[0] != '0')
            numDecodingsPos[0] = 1;
        
        if(s.length() < 2){
            return numDecodingsPos[0];
        }
        
        int tmp = string2Num(s, 0, 2);
        numDecodingsPos[1] = numDecodingsPos[0];
        if(tmp >= 10 && tmp <= 26){
            if(s[1] != '0'){
                numDecodingsPos[1] = 2;
            }
        }
        
        for(int i = 2; i < s.size(); i++){
            int others = 0;
            tmp = string2Num(s, i - 1, 2);
            if(tmp >= 10 && tmp <= 26){
                others = numDecodingsPos[i - 2];
            }
            
            if(s[i] != '0'){
                numDecodingsPos[i] = numDecodingsPos[i - 1] + others;
            }
            else{
                numDecodingsPos[i] = others;
            }
        }
        
        return numDecodingsPos[s.length() - 1];
    }
};