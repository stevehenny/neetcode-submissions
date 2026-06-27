class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> numToInd;

        for(int i{}; i < nums.size(); ++i){
            // first compute the current complement
            int c = target - nums[i];

            // if complement is found in map, return 
            // value correlated to the key and current ind
            if(numToInd.count(c)){
                return {numToInd[c], i};
            }

            // otherwise, add the value: ind pair to the map
            numToInd[nums[i]] = i;
        }

        return {};
    }
};
