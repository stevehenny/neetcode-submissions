class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int &num: nums){
            ++m[num];
        }

        // now find the k most frequent elements;
        vector<std::pair<int, int>> pairs(m.begin(), m.end());


        std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        vector<int> ret;
        for(int i{}; i < k; ++i){
            ret.push_back(pairs[i].first);
        }
        return ret;
    }
};
