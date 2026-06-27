class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left{};
        int right = 1;
        int ret{};
        while(right < prices.size()){
            ret = max(ret, prices[right] - prices[left]);
            if(prices[right] < prices[left]){
                left = right;
                ++right;
            }
            else{
                ++right;
            }
        }
        return ret;
        
    }
};
