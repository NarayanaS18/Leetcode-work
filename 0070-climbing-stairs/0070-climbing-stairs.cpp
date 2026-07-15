class Solution {
public:

    int f(int idx, vector<int> &dp){
        if(idx == 0) return 1;
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];
        int j1 = f(idx-1, dp);
        int j2 = f(idx-2, dp);

        return dp[idx] = j1+j2;
    }

    int climbStairs(int n) {
        int prev = 1, prev2 = 1;
        for(int i=2; i<=n; i++){
            int j1 = prev;
            int j2 = prev2;
            int curi = j1 + j2;
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
};