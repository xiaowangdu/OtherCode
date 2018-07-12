class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
     
    bool matched(const string &s1, const string &s2){
        if(s1 == "*" || s2 == "*"){
            return true;
        }
        
        if((s1 == "?" && !s2.empty()) || (s2 == "?" && !s1.empty())){
            return true;
        }
        
        return s1 == s2;
    }
     
    bool isMatch(string &s, string &p) {
        // write your code here
        if(s.length() <= 0 && p.length() <= 0){
            return true;
        }
        
        if(s.length() <= 0){
            for(int i = 0; i < p.length(); i++) {
                if(p[i] != '*') return false;
            }
            return true;
        }
        
        if(p.length() <= 0){
            for(int i = 0; i < s.length(); i++) {
                if(s[i] != '*') return false;
            }
            return true;
        }
        
        int M = s.length(), N = p.length();
        vector<vector<int>> matchedPos;
        for(int i = 0; i < M; i++){
            vector<int> tmp(N, 0);
            matchedPos.push_back(tmp);
        }
        
        string stmp(1, s[0]);
        for(int i = 0; i < N; i++){
            if(stmp == "*"){
                matchedPos[0][i] = 1;
            }
            else{
                matchedPos[0][i] = matched(stmp, string(1, p[i]));
                if(p[i] != '*'){
                    if(matchedPos[0][i]){
                        stmp.clear();
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        stmp = string(1, p[0]);
        for(int i = 0; i < M; i++){
            if(stmp == "*"){
                matchedPos[i][0] = 1;
            }
            else{
                matchedPos[i][0] = matched(stmp, string(1, s[i]));
                if(s[i] != '*'){
                    if(matchedPos[i][0]){
                        stmp.clear();
                        continue;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        for(int i = 1; i < M; i++){
            for(int j = 1; j < N; j++){
                if(s[i] == '*' || p[j] == '*'){
                    matchedPos[i][j] = matchedPos[i - 1][j] | matchedPos[i - 1][j - 1] | matchedPos[i][j - 1];
                } 
                else{
                    if(matched(string(1, s[i]), string(1, p[j]))){
                        matchedPos[i][j] = matchedPos[i - 1][j - 1];
                    }
                    else{
                        matchedPos[i][j] = 0;
                    }
                }
            }
        }
        
        return matchedPos[M - 1][N - 1];
    }
};