class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        //init adj_list
        unordered_map<int, vector<pair<int,int>>> adj_list;
        for(auto& flight: flights){
            adj_list[flight[0]].push_back({flight[1], flight[2]});
        }
        
        // init dist and pq
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // [cost, u, cur_k];
        priority_queue<tuple<int,int,int>,
                        vector<tuple<int,int,int>>,
                        std::greater<>> pq;

        pq.push(tuple<int,int,int>{0, src, 0});

        while(!pq.empty()){
            auto [cost, u, cur_k] = pq.top();
            pq.pop();

            for(auto& [v, w]: adj_list[u]){
                int new_cost = w + cost;

                if(cur_k >= k && v != dst) continue;

                if(new_cost < dist[v]){
                    dist[v] = w + cost;
                    pq.push(tuple<int,int,int>{w + cost, v, cur_k + 1});
                }
            }
        }

  
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
