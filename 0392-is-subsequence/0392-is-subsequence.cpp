class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        int i = 0, j = 0;
        string temp = "";
        while(i < m && j < n){
            if(s[i] != t[j]){
                j++;
            }
            else if(s[i] == t[j]){
                temp += s[i];
                i++;j++;
            }
        }
        return temp.length() == m;
    }
};