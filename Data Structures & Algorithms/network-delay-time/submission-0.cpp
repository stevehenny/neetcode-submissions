class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long> dist(n, INT_MAX);

        dist[k-1] = 0;
        for(int i{}; i < n; ++i){
            for(vector<int>& time: times){
                if(dist[time[0] - 1] == INT_MAX) continue;
                dist[time[1]-1] = std::min(dist[time[1]-1], dist[time[0]-1] + time[2]);
            }
        }
        long max_time{};
        for(int i{}; i < n; ++i){
            max_time = std::max(max_time, dist[i]);
        }
        if(max_time == INT_MAX) return -1;

        return max_time;



    }
};
