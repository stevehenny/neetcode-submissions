class Solution {
private:
    int get_digit_sum(int n){
        int sum{};
        while(n > 0){
            int cur = n % 10;
            sum += (cur * cur);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        int curSum = get_digit_sum(n);
        while(!seen.count(curSum)){
            seen.insert(curSum);
            if(curSum == 1) return true;
            curSum = get_digit_sum(curSum);
        }
        return false;

    }
};
