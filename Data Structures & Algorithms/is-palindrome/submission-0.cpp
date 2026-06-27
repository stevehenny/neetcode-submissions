class Solution {
public:
    bool isPalindrome(string s) {
   
    s.erase(std::remove_if(s.begin(), s.end(), 
                             [](unsigned char c){ return std::isspace(c) || std::ispunct(c); }),
              s.end());

    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::string dup = s;

    std::cout<<s;
    std::reverse(dup.begin(), dup.end());
    return s == dup;
}
  

};
