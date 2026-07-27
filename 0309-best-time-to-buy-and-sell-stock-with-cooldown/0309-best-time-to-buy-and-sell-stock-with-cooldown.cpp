class Solution {
public:

    int f(int idx, bool holding, vector<int>& prices, vector<vector<int>>& dp){
        int n = prices.size();
        if(idx >= n) return 0;
        int max1 = 0, max2 = 0;
        if(dp[idx][holding] != -1) return dp[idx][holding];
        if(holding){
            int sell = prices[idx] + f(idx+2, false, prices, dp);
            int hold = f(idx+1, true, prices, dp);
            max1 = max(sell, hold);
        }
        else{
            int buy = -prices[idx] + f(idx+1, true, prices, dp);
            int rest = f(idx+1, false, prices, dp);
            max2 = max(buy, rest);
        }
        return dp[idx][holding] = max(max1, max2);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, false, prices, dp);
    }
};