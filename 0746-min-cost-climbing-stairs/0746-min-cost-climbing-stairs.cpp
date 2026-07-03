class Solution {
public:

    int f(int idx, int n, vector<int>& cost, vector<int>& dp){
        if(idx == n) return 0;
        int jump1 = 0, jump2 = 0;
        if(dp[idx] != -1) return dp[idx];
        if(idx+1 <= n) jump1 = f(idx+1, n, cost, dp);
        if(idx+2 <= n) jump2 = f(idx+2, n, cost, dp);
        return dp[idx] = cost[idx] + min(jump1, jump2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+2, 0); // to handle i+1 and i+2 jumps
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }  
        return min(dp[0], dp[1]);
    }
};