class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1]++;
        bool carry = (digits[n-1] == 10) ? true : false;
        for(int i{n-1}; i > 0; --i){
            if(carry){
                digits[i] = 0;
                digits[i-1]++;
            }

            carry = (digits[i-1] == 10) ? true : false;
        }

        if(carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
