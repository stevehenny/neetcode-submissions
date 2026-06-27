class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto vecSort = [&](const vector<int>& a, const vector<int>& b){
            float dist1 = sqrt((a[0] - 0) * (a[0] - 0) + (a[1] - 0) * (a[1]- 0));
            float dist2 = sqrt((b[0] - 0) * (b[0] - 0) + (b[1] - 0) * (b[1] - 0));
            return dist2 < dist1;
        };

        std::priority_queue<vector<int>, vector<vector<int>>, decltype(vecSort)> q(vecSort);

        for(auto& point : points){
            q.push(point);
        }

        vector<vector<int>> ret;
        for(int i = 0; i < k; ++i){
            ret.push_back(q.top());
            q.pop();
        }

        return ret;
    }
};
