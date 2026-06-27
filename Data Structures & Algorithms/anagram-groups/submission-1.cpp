

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string& s: strs){
            const string temp = s;
            std::sort(s.begin(), s.end());
            m[s].push_back(temp);
        }
        vector<vector<string>> ret;
        for(auto &[k,v]: m){
            ret.push_back(v);
        }
        return ret;
    }
};
