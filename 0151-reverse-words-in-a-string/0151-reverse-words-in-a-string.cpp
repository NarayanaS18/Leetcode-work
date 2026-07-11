class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int idx = n-1;
        string ans = "";
        while(idx >= 0){
            while(idx >= 0 && s[idx] == ' '){
                idx--;
            }
            if(idx < 0){
                break;
            }
            int right = idx;
            while(idx >= 0 && s[idx] != ' '){
                idx--;
            }
            if(!ans.empty()){
                ans += ' ';
            }  
            
            ans += s.substr(idx+1, right-idx);
        }
        return ans;
    }
};