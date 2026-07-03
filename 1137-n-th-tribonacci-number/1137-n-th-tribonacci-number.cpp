class Solution {
public:

    int f(int i, vector<int>& dp){
        if(i == 0 || i == 1) return i;
        if(i == 2) return 1;
        if(dp[i] != -1) return dp[i];
        return dp[i] = f(i-1, dp) + f(i-2, dp) + f(i-3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n+2, -1);
        return f(n, dp);
    }
};