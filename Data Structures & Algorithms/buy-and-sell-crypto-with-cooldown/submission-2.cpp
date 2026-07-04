class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        std::vector<int> hold(n, 0);
        std::vector<int> sold(n, 0);
        std::vector<int> rest(n, 0);
        hold[0] = -prices[0];

        for(int i{1}; i < n; ++i){
            hold[i] = std::max(hold[i-1], rest[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            rest[i] = std::max(rest[i-1], sold[i-1]);
        }

        return std::max({hold[n-1], sold[n-1], rest[n-1]});
    }
};
