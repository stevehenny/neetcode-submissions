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
            int window = r - left + 1;
            while(window - maxFreq > k){
                freq[s[left]]--;
                left++;
                window--;
            }
            ret = max(ret, window);
        }
        
    return ret;
    }
};
