class Solution {
public:
    int getSum(int a, int b) {
        int res{};
        bool carry_flag{false};
        for(int i{}; i < 32; ++i){
            if(carry_flag){
                res |= (((a ^ b) ^ (1 << i)) & (1 << i));

                carry_flag = ((a >> i) & 1) || ((b >> i) & 1);
            }
            else{
                res |= ((a ^ b) & (1 << i));

                carry_flag = ((a >> i) & 1) && ((b >> i) & 1); 
            }
        }

        return res;
    }
};
