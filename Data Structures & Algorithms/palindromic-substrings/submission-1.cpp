class Solution {
public:
    int countSubstrings(string s) {
        int total_count{};
        int l, r;
        int n = s.length();
        for(int i{}; i < n; ++i){
            ++total_count;
            // check odd palindromes
            l = i, r = i;
            while(l > 0 && r < n-1 &&s[l] == s[r]){
                if(s[l-1] == s[r+1]){
                    ++total_count;
                }
                --l;
                ++r;
            }

            // check odd
            if(i < n-1 && s[i] == s[i+1]){
                l = i;
                r = i+1;
                ++total_count;
                while(l > 0 && r < n-1 &&s[l] == s[r]){
                if(s[l-1] == s[r+1]){
                    ++total_count;
                }
                --l;
                ++r;
                }
            }
        }
        return total_count;
    }
};
