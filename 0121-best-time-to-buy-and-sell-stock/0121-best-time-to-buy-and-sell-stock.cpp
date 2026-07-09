class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), bestBuy = prices[0], maxProfit = 0;
        for(int i=1; i<n; i++){
            if(prices[i] > bestBuy){
                maxProfit = max(maxProfit, prices[i]-bestBuy);
            }
            bestBuy = min(bestBuy, prices[i]);
        }
        return maxProfit;
    }
};