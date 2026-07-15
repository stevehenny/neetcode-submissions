class Solution {
private:
    unordered_map<int, double> memo;
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == -1) return 1/x;
        if(n == 1) return x;

        if(memo.find(n) != memo.end())
            return memo[n];

        if(n > 0)
            memo[n] = myPow(x, n / 2) * myPow(x, ((n + 1) / 2));
        else
            memo[n] = myPow(x, n / 2) * myPow(x, ((n - 1) / 2));
        return memo[n]; 
    }
};
