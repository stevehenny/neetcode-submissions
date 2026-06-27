class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, std::greater<int>> q;
        int n = nums.size();
        for(auto num: nums){
            q.push(num);
            if(q.size() > k) q.pop();
        }

        return q.top();
    }
};
