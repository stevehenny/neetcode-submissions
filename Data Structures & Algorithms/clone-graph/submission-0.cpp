/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* ret;
    std::unordered_map<Node*, Node*> nodeMap;
    void dfs(Node* node){
        if(!node) return;
        // we have already seen this node
        if(nodeMap.count(node)) return;

        nodeMap[node] = new Node(node->val);
        for(Node* neighbor: node->neighbors){
            dfs(neighbor);
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        // init nodeMap via dfs
        Node* ptr = node;
        dfs(ptr);

        // make sure neighbors lists are correct
        for(auto &[k,v]: nodeMap){
            for(Node* neighbor: k->neighbors){
                v->neighbors.push_back(nodeMap[neighbor]);
            }
        }
        return nodeMap[node];
    }
};
