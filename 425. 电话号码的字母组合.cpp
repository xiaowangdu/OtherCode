class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
     
    void combinations(vector<string> &res, vector<char> &alph, vector<string> &src, int row){
        if(alph.size() >= src.size()){
            string str(src.size(), ' ');
            for(int i = 0; i < alph.size(); i++){
                str[i] = alph[i];
            }
            res.push_back(str);
            
            return;
        }
        
        for(int i = row; i < src.size(); i++){
            for(int j = 0; j < src[i].size(); j++){
                alph.push_back(src[i][j]);
                combinations(res, alph, src, i + 1);
                alph.pop_back();
            }
        }
    }
     
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> res;
        if(digits.empty()){
           return res;
        }
        
        //init
        string dicts[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> src;
        for(int i = 0; i < digits.size(); i++){
            string s(1, digits[i]);
            int key = atoi(s.data());
            if(key == 0){
                src.push_back(string(" "));
                continue;
            }
            else if(key == 1){
                return vector<string>();
            }
            src.push_back(dicts[key - 2]);
        }
        
        vector<char> alph;
        combinations(res, alph, src, 0);
        
        return res;
    }
};