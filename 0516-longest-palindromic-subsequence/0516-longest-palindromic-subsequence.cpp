class Solution {
public:

    int f(string s1, string s2){
        int m = s1.length(), n = s2.length();
        vector<int> prev(n+1, 0), cur(n+1, 0);

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1]){
                    cur[j] = 1 + prev[j-1];
                }
                else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return f(s, s2);
    }
};