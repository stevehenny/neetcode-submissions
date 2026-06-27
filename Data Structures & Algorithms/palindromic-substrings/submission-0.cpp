class Solution {
public:
    int countSubstrings(string s) {
        int count{};

        int n = s.length();
        for(int i{}; i < n; ++i){

            // check odd palindromes
            int l = i;
            int r = i;
            while(l >=0 && r < n && s[l] == s[r]){
                ++count;
                --l;
                ++r;
            }


            // check for even palindromes
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                ++count;
                --l;
                ++r;
            }
        }
        return count;
    }
};
