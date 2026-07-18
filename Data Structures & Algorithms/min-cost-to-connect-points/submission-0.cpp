class Solution {
private:
    int _min_tree_cost{0};
public:
    int find(vector<int>& parent, int i){
        if(parent[i] == i) return i;

        parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    void union_join(vector<int>& parent, vector<int>& rank, int root_i, int root_j){
        // int root_i = find(parent, i);
        // int root_j = find(parent, j);

        // if(root_i != root_j){

            if(rank[root_i] < rank[root_j]) std::swap(root_i, root_j);

            parent[root_j] = root_i;
            rank[root_i] += rank[root_j];
        // }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        std::vector<int> parent(n, 1);
        std::vector<int> rank(n, 1);

        // <w, u, v>
        vector<std::tuple<int,int,int>> edges;
        edges.reserve(n * n); 
        for(int i{}; i < n; ++i) parent[i] = i;

        //create edges
        for(int i{}; i < n; ++i){
            for(int j{i}; j < n; ++j){
                int w = std::abs(points[i][0] - points[j][0]) + std::abs(points[i][1] - points[j][1]);
                edges.emplace_back(std::tuple<int,int,int>{w, i, j});
            }
        }

        //sort edges
        std::sort(edges.begin(), edges.end());

        for(int i{}; i < edges.size(); ++i){
            auto [w, u, v] = edges[i];
            int root_u = find(parent, u);
            int root_v = find(parent, v);
            if(root_u != root_v){
                union_join(parent, rank, root_u, root_v);
                _min_tree_cost += w;
            }
        }
        return _min_tree_cost;



    }
};
