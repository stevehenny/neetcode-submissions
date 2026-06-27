class Solution {
public:
    int hammingWeight(uint32_t n) {
        return std::bitset<32>(n).count();
    }
};
