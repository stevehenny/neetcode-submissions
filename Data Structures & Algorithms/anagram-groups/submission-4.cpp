
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       std::unordered_map<string, vector<string>> anagrams;

        // O(m) -> m strings
        for(auto& s: strs){
            // track the frequences of the lowercase characters
            // in the current string
            vector<int> freq(26, 0);
            for(int i{}; i < s.length(); ++i){
                freq[s[i] - 'a']++;
            }

            string key = to_string(freq[0]);
            for(int i = 1; i < 26; ++i){
                key +=  ',' + to_string(freq[i]);
            }

            anagrams[key].push_back(s);
        }


        vector<vector<string>> ans;
        for( auto &[k, v]: anagrams){
            ans.push_back(v);
        }
        return ans;
    }
};
