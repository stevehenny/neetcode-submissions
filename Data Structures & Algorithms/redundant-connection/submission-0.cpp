class Solution {

private:
    int find(vector<int>& parent, int i){
        if(parent[i] == i) return i;

        parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    void union_find(vector<int>& parent, vector<int>& rank, int root_i, int root_j){

        if(root_i < root_j) std::swap(root_i, root_j);

        parent[root_j] = root_i;
        rank[root_i] += rank[root_j];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n, 0);
        vector<int> rank(n, 1);

        for(int i{}; i < n; ++i) parent[i] = i;

        for(auto& edge: edges){
            int root_u = find(parent, edge[0]-1);
            int root_v = find(parent, edge[1]-1);
            if(root_u != root_v){
                union_find(parent, rank, root_u, root_v);
            }
            else{
                return edge;
            }
        }
        return {};
    }
};
