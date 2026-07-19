class Solution {
private:
    unordered_map<string, vector<string>> adj_list;
    vector<string> res;
    
    void dfs(string cur_city){
        while(!adj_list[cur_city].empty()){
            string next_city = adj_list[cur_city][0];
            adj_list[cur_city].erase(adj_list[cur_city].begin());
            dfs(next_city);
        }
        res.emplace_back(cur_city);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {


        for(auto& ticket: tickets){
        adj_list[ticket[0]].emplace_back(ticket[1]);
        }
        
        for(auto& [k, v]: adj_list){
            std::sort(v.begin(), v.end());
      
        }

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
