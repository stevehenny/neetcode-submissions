class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        int c;
        for(int i{}; i < nums.size(); ++i){
            c = target - nums[i];
            cout << c;
            if(complements.count(c)){
                return { complements[c], i};
            }
            
            complements[nums[i]] = i;
        }
        return {};
    }
};
