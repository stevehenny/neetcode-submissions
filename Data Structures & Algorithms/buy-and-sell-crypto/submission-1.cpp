class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int left = 0;
        int right = 1;
        while(right < prices.size()){
            ret = max(ret, prices[right] - prices[left]);
            if(prices[left] > prices[right]) left = right;



            ++right;
        }

        return ret;
    }
};
