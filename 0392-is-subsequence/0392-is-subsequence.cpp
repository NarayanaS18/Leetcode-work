class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0, cnt = 0;
        
        while(i < m && j < n){
            if(s[i] != t[j]){
                j++;
            }
            else if(s[i] == t[j]){
                cnt++;
                i++;j++;
            }
        }
        return cnt == m;
    }
};