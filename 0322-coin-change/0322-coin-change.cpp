class Solution {
public:

    int f(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notPick = 0 + f(ind-1, coins, amount, dp);
        int pick = 1e9;
        if(coins[ind] <= amount){
            pick = 1 + f(ind, coins, amount-coins[ind], dp);
        }

        return dp[ind][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int t=0; t<=amount; t++){
            if(t % coins[0] == 0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }

        for(int ind=1; ind<n; ind++){
            for(int t=1; t<=amount; t++){
                int notPick = 0 + dp[ind-1][t];
                int pick = 1e9;
                
                if(coins[ind] <= t){
                    pick = 1 + dp[ind][t - coins[ind]];
                }

                dp[ind][t] = min(pick, notPick);
            }
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};