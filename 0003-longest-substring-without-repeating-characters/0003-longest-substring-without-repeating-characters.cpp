class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int len = 0, maxlen = 0;
        vector<int> hash(256, -1);

        while(i < n && j < n){
            if(hash[s[j]] != -1){
                if(hash[s[j]] >= i) i = hash[s[j]] + 1;
            }

            len = j-i+1;
            maxlen = max(len, maxlen);
            hash[s[j]] = j;
            j++;
        }
        return maxlen;
    }
};