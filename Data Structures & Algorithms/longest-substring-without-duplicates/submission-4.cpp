class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> freq;
        int left = 0;
        int right =0;
        
        int ret = 0;
        while(right < s.length()){
            // cur char pointed to by right side of 
            // window exists in current window
            if(freq.count(s[right])){
                while(left != right && freq[s[right]]){
                    freq[s[left]]--;
                    ++left;
                }
            }
            freq[s[right]]++;
            ret = max(ret, right - left + 1);



            ++right;
        }
        return ret;

    }
};
