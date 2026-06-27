class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ret(n);
        std::stack<std::pair<int, int>> q;
        
        for(int i{}; i < n; i++){
            while(!q.empty() && temperatures[i] > q.top().second){
                auto cur = q.top();
                q.pop();
                ret[cur.first] = i - cur.first;
            }
            q.push({i, temperatures[i]});
    }
    return ret;
    }
};
