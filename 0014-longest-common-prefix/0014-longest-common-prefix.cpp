class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        sort(strs.begin(), strs.end());
        string ans = "";
        string first = strs[0], last = strs[n-1];
        int minlen = min(first.length(), last.length());
        for(int i=0; i<minlen; i++){
            if(first[i] != last[i]){
                break;
            }
            ans += first[i];
        }
        return ans;
    }
};