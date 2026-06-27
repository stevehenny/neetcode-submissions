class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        for(int i{}; i < s.length(); ++i){
            ++sMap[s[i]];
            ++tMap[t[i]];
        }

        return sMap == tMap;
    }
};
