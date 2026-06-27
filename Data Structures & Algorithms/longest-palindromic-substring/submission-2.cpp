class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen{};
        int maxLeft{};
        for(int i{}; i < n; ++i){
            
            // check od strings
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLeft = l;
                    maxLen = r - l + 1;
                }
                ++r;
                --l;
            }

            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    maxLeft = l;
                    maxLen = r - l + 1;
                }
                ++r;
                --l;
            }
            
        }
        std::cout << maxLen;
        return s.substr(maxLeft, maxLen);
    }
};
