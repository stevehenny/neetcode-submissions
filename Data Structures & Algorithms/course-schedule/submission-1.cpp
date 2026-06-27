class Solution {
    unordered_set<int> visited;
    unordered_map<int,  vector<int>> preMap;

    bool dfs(int curNode){

        if(visited.count(curNode)) return false;

        if(preMap[curNode].empty()) return true;

        visited.insert(curNode);

        // now dfs on all other nodes
        for(int node: preMap[curNode]){
            if(!dfs(node)) return false;
        }
        visited.erase(curNode);
        preMap[curNode].clear();
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // must take course b before a in prereqs [a,b] pairs
        // init preMap
        for(vector<int>& vec: prerequisites){
            preMap[vec[0]].emplace_back(vec[1]);
        }

        for(int i{}; i < numCourses; ++i){
            if(!dfs(i)) return false;
        }

        return true;
    }
 };
