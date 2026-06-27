class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        for(int i{}; i <= n; ++i){
            res[i] = std::bitset<32>(i).count();
        }
        return res;
    }
};
