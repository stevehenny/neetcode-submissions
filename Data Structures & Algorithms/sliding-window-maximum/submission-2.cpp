class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        std::priority_queue<std::pair<int,int>> q;
        vector<int> ret;

        // init window
        for(int i{}; i < k; ++i){
            q.push({nums[i], i});
        } 
        ret.push_back(q.top().first);
        for(int i = k; i < nums.size(); ++i){
            q.push({nums[i], i});
            if(i >= k - 1){
            while(q.top().second <= i - k){
                q.pop();
                cout << q.top().second;
            }
            ret.push_back(q.top().first);
            }
            
        }

        return ret;
    }
};
