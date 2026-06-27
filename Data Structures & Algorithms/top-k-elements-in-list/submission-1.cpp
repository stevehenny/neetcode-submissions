class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int,int> numToFreq;
    // O(n) -> where n is the number of inputs in nums
    for(int &num: nums){
        numToFreq[num]++;
    }

    // now that we have the frequencies, lets sort the unordered_map
    // O(n log(n)) -> where n is the number of kv pairs 
    vector<std::pair<int,int>> pairs(numToFreq.begin(), numToFreq.end());
    std::sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
    });

    // now that we have the unordered_map in decreasing order, construct answer
    int i = 0;
    vector<int> ans;
    for(auto it = pairs.begin(); i<k; ++i){
        ans.push_back(it->first);
        ++it;
    }



    return ans;
    }
};
