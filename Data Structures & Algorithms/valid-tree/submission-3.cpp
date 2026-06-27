class Solution {
private:
    std::unordered_set<int> visited;
    std::unordered_map<int, vector<int>> adjList;

    bool dfs(int curNode, int prevNode){
        visited.insert(curNode);
        for(int i{}; i < adjList[curNode].size(); ++i){
            if(adjList[curNode][i] == prevNode) continue;
            if(visited.count(adjList[curNode][i])) return false; // detected a cycle
            if(!dfs(adjList[curNode][i], curNode)) return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // initialize adjacency list
        for(const vector<int> &edge: edges){
            if(edge[0] == edge[1]) return false;
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // call dfs 0
        visited.insert(0);
        for(int i{}; i < adjList[0].size(); ++i){
            if(!dfs(adjList[0][i], 0)) return false;
        }

        return visited.size() == n;
    }
};
