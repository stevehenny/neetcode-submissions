class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left{};
        int right{};
     
        int ret{};
        unordered_map<char,int> m;
        while(right < s.length()){
            m[s[right]]++;
            while(m[s[right]] > 1){
                m[s[left]]--;
                left++;
            }
            right++;
            ret = max(ret, right - left);
        }

        return ret;
    }
};
