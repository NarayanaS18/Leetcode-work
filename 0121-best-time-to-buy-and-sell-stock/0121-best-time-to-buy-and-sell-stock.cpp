class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0, bestBuy = prices[0];
        for(int price : prices){
            if(price > bestBuy){
                maxProfit = max(maxProfit, price-bestBuy);
            }
            bestBuy = min(bestBuy, price);
        }
        return maxProfit;
    }
};