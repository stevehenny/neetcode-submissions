class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<std::pair<int, int>> pos_speed;
        for(int i{}; i < position.size(); ++i){
            pos_speed.push_back({position[i], speed[i]});
        } 
        std::sort(pos_speed.begin(), pos_speed.end(), [](std::pair<int,int>& a, std::pair<int,int>& b){
            return a.first > b.first;
        });

        std::stack<std::pair<int, int>> q;
        int fleet_count{};
        for(auto& p: pos_speed){
            
            double time_to_arrive = double(target - p.first) / p.second;
            double top_time_to_arrive{};
            if (!q.empty())
                top_time_to_arrive = (double)(target - q.top().first) / q.top().second;
            if(time_to_arrive <= top_time_to_arrive) continue;
            
            q.push(p);
        }
        return q.size();
    }
};
