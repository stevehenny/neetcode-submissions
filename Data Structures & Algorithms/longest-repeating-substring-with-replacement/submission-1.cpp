class Solution {
public:
    int characterReplacement(string s, int k) {
        int left{};
        int ret{};
        int maxFreq{};
        std::unordered_map<char, int> freq;
        for(int r{}; r < s.length(); ++r){
            ++freq[s[r]];
            maxFreq = max(maxFreq, freq[s[r]]);

            while((r - left + 1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            ret = max(ret, r - left  +1);
        }
        
    return ret;
    }
};
