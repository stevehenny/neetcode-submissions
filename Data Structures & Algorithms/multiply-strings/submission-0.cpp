class Solution {
public:
    string multiply(string num1, string num2) {
        unsigned long long product{};
        int n = num1.length();
        int m = num2.length();


        vector<int> res(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int cur_prod = (num1[i] - '0') * (num2[j] - '0');
                res[j+i+1] += cur_prod;
            }
        }

        for(int i{n + m - 1}; i > 0; --i){
            res[i-1] += res[i] / 10;
            res[i] %= 10;
        }

        int pos = 0;
        while (pos < res.size() - 1 && res[pos] == 0)
            ++pos;

        string ans;
        for (; pos < res.size(); ++pos)
            ans += res[pos] + '0';

        return ans;

    }
};
