class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[n-1];
        string ans = "";
        int minlen = min(first.length(), last.length());
        for(int i=0; i<minlen; i++){
            if(first[i] != last[i]) break;
            ans += first[i]; 
        }
        return ans;
    }
};