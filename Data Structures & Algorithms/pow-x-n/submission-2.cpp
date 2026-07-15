class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == 2) return x * x;
        
        int na = abs(n);
        double ans;
        if(n % 2 == 0){
            ans = myPow(myPow(x, na/2), 2);
        }
        else{
            ans = x*myPow(myPow(x, na/2), 2);
        }

        if(n > 0){
            return ans;
        }
        else{
            return 1/ans;
        }

        
    }
};
