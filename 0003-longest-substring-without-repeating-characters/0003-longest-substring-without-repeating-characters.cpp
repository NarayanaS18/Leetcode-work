class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        int maxlen = 0, len = 0;
        for(int i=0; i<n; i++){
            int hash[256] = {0};
            string s1 = "";
            for(int j=i; j<n; j++){
                if(hash[s[j]] == 1){
                    break;
                }
                s1 += s[j];
                len = j-i+1;
                maxlen = max(maxlen, len);
                hash[s[j]] = 1;
            }
        }
        return maxlen;
    }
};