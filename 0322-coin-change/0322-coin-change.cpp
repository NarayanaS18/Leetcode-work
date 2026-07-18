class Solution {
public:

    int f(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dp[amount] != -2) return dp[amount];
        int mini = INT_MAX;
        for(int coin : coins){
            int res = f(coins, amount - coin, dp);

            if(res >= 0 && res < mini){
                mini = 1 + res;
            }
        }
        return dp[amount] = (mini == INT_MAX) ? -1 : mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -2);
        return f(coins, amount, dp);
    }
};