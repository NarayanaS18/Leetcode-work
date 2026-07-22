class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int m = strs[0].length();
        string s1 = strs[0], s2 = strs[n-1], ans = "";
        for(int i=0; i<m; i++){
            if(s1[i] != s2[i]){
                break;
            }
            ans += s1[i];
        }
        return ans;
    }
};