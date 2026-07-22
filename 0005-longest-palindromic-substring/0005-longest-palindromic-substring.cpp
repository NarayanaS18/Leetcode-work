class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(s.empty()) return "";
        int st = 0, maxlen = 0;

        auto expandAroundCorner = [&](int left, int right){
            while(left >= 0 && right < n && s[left] == s[right]){
                left--; right++;
            }
            int len = right-left-1;
            if(len > maxlen){
                maxlen = len;
                st = left + 1;
            }
        };

        for(int i=0; i<n; i++){
            expandAroundCorner(i, i);//odd length palindrome
            expandAroundCorner(i, i+1);//even length palindrome
        }
        return s.substr(st, maxlen);
    }
};