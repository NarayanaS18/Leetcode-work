class Solution {
public:

    int f(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0;
        
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }

    int longestCommonSubsequence(string s1, string s2) {
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
};