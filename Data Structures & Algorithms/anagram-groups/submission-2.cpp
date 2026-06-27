

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       std::unordered_map<string, vector<string>> anagrams;

        for(auto& s: strs){
            // copy assignment
            std::string temp = s;

            std::sort(temp.begin(), temp.end());
            anagrams[temp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto &[k, v]: anagrams){
            ans.push_back(v);
        }
        return ans;
    }
};
