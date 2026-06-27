class Solution {
private:
    std::unordered_map<int,int> memo;
    int dfs(vector<int>& coins, int curAmount){

        // base cases
        if(curAmount == 0) return 0;
        if(memo.count(curAmount)) return memo[curAmount];

        // now loop through coins and gather sums
        int res = INT_MAX;
        for (int coin : coins) {
            if (curAmount - coin >= 0) {
                int result = dfs(coins, curAmount - coin);
                if (result != INT_MAX) {
                    res = min(res, 1 + result);
                }
            }
        }
         memo[curAmount] = res;
        return res;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }
};
