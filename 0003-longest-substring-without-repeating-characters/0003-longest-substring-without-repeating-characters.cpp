class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int n = s.length();
        int i = 0, j = 0, maxlen = 0;
        while(j < n){
            if(hash[s[j]] != -1){//means its already present before
                if(hash[s[j]] >= i){
                    i = hash[s[j]] + 1;
                }
            }
            int len = j - i + 1;
            maxlen = max(maxlen, len);
            hash[s[j]] = j;
            j++;
        }
        return maxlen;
    }
};