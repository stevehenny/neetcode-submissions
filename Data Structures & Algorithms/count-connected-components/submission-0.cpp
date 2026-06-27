class Solution {
private:
    std::unordered_set<int> visited;
    std::unordered_map<int, vector<int>> adjList;
    int count;

    void dfs(int curNode){
        if(visited.count(curNode)) return;
        visited.insert(curNode);
        for(int i{}; i < adjList[curNode].size(); ++i){
            dfs(adjList[curNode][i]);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // initialize adjList
        for(const vector<int>& edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // now run the dfs
        count = 0;
        for(int i = 0; i < n; ++i){
            if(visited.count(i)) continue;
            ++count;
            dfs(i);
        }


        return count;
    }
};
