class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        // compute cost/gas tradeoff
        int n = gas.size();
        for(int i = 0; i < n; ++i){
            gas[i] -= cost[i];
        }

        if(std::accumulate(gas.begin(), gas.end(),0) < 0){
            return -1;
        }

        // now use gas to compute a dp array backwards.
        vector<int> dp(n, 0);
        dp[n-1] = gas[n-1];
        for(int i = n - 2; i >= 0; --i){
            dp[i] = dp[i +1] + gas[i];
        }

        // now find max ind
        int curMax = INT_MIN;
        int maxInd = -1;
        for(int i = 0; i < n; ++i){
            if(curMax < dp[i]){
                maxInd = i;
                curMax = dp[i];
            }
        }
        return maxInd;
    }
};
