class Solution {
private:

public:
    int reverse(int x) {
        
        int accum{};
        bool negative = (x < 0);
        x = (negative) ? (x * -1) : x;
        while(x > 0){
           int leadingDigit = x % 10;
           if(accum > (std::numeric_limits<int>::max() / 10) - leadingDigit) return 0; 
           accum *= 10; 
           
           accum += leadingDigit;
           
           x /= 10; 
        }
        std::cout << accum;
        
        return (negative) ? (-accum) : accum;


    }
};
