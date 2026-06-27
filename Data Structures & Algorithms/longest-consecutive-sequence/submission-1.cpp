class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxSeq{};
        for(int &num: nums){
            if(!m[num]){
                m[num] = m[num-1] + m[num + 1] + 1;
                m[num - m[num-1]] = m[num];
                m[num + m[num +1]] = m[num];
                maxSeq = max(maxSeq, m[num]);
        }
    }
    return maxSeq;
    }
};
