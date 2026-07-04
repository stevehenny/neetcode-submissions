class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1) return 0;
        int hold{-prices[0]};
        int sold{};
        int rest{};
        for(int i{1}; i < prices.size(); ++i){
            int prev_hold = hold;
            int prev_sold = sold;
            int prev_rest = rest;

            hold = std::max(prev_hold, prev_rest - prices[i]);
            sold = prev_hold + prices[i];
            rest = std::max(prev_rest, prev_sold);
        }

        return std::max({hold, sold, rest});
    }
};
