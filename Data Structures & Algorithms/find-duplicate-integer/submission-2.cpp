class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> seen(n, 0);
        for(int num: nums){
            if(seen[num-1] == 1) return num;

            seen[num-1] = 1;
        }
        return -1;
    }
};
