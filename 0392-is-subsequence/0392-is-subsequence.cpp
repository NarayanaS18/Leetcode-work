class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        string temp = "";
        int i = 0, j = 0;
        while(i < m && j < n){
            if(s[i] != t[j]){
                j++;
            }
            if(s[i] == t[j]){
                temp += t[j];
                i++; j++;
            }
        }
        if(temp.find(s) != string::npos) return true;
        
        return false;
    }
};