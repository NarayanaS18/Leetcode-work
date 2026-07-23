class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxlen = 0, st = 0;
        auto expandAroundCorner = [&](int left, int right){
            while(left >= 0 && right < n && s[left] == s[right]){
                left--; right++;
            }
            int len = right - left - 1;
            if(len > maxlen){
                maxlen = len;
                st = left+1;
            }
        };

        for(int i=0; i<n; i++){
            expandAroundCorner(i, i);
            expandAroundCorner(i, i+1);
        }
        return s.substr(st, maxlen);
    }
};