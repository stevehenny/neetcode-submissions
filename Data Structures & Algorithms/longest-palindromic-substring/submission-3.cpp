class Solution {
   public:
    string longestPalindrome(string s) {
        int start_ind{};
        int res_len{};
        int n = s.length();
        int l, r;

        for (int i{}; i < s.length(); ++i) {
            // check the initial odd palindrome
            l = i;
            r = i;
            while (l > 0 && r < n - 1) {
                if (s[l-1] != s[r+1]) break;
                --l;
                ++r;
            }

            int cur_len{r - l + 1};
            if (cur_len > res_len) {
                res_len = cur_len;
                start_ind = l;
                
            }
            // even case
            if(s[i] == s[i+1]){
                l = i;
                r = i + 1;
                while (l > 0 && r < n - 1) {
                    if (s[l-1] != s[r+1]) break;
                    --l;
                    ++r;
                }

                int cur_len{r - l + 1};
                if (cur_len > res_len) {
                    res_len = cur_len;
                    start_ind = l;
                    
                }
            }
        }

        return s.substr(start_ind, res_len);
    }
};
