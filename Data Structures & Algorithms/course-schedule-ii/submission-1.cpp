class Solution {
    unordered_set<int> visited;
    unordered_map<int,  vector<int>> preMap;
    std::vector<int> ret;
    std::unordered_set<int> curSet;
    bool dfs(int curNode){

        if(visited.count(curNode)) return false;

        if(curSet.count(curNode)) return true;

        visited.insert(curNode);

        // now dfs on all other nodes
        for(int node: preMap[curNode]){
            if(!dfs(node)) return false;
        }

        curSet.insert(curNode);
        ret.push_back(curNode);
        visited.erase(curNode);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // must take course b before a in prereqs [a,b] pairs
        // init preMap
        for(vector<int>& vec: prerequisites){
            preMap[vec[0]].push_back(vec[1]);
        }

        for(int i{}; i < numCourses; ++i){
            if(!dfs(i)) return {};
        }

        return ret;
    }
 };
