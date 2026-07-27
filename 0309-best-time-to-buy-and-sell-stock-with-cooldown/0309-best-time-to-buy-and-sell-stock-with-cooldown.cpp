class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        int held = INT_MIN;
        int sold = 0;
        int rest = 0;

        for(int price : prices){
            int prev_held = held;
            int prev_sold = sold;
            int prev_rest = rest;

            held = max(prev_held, prev_rest - price);
            sold = prev_held + price;
            rest = max(prev_rest, prev_sold);
        }
        return max(sold, rest);
    }
};