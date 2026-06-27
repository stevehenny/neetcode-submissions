/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// THIS IS A BFS PROBLEM -> USE A QUEUE
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        std::queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty()){

            vector<int> curLevel;
            vector<TreeNode*> popped;
            while(!q.empty()){
                TreeNode* temp = q.front();
                q.pop();
                curLevel.push_back(temp->val);
                popped.push_back(temp);
            }
            res.push_back(curLevel);
            for(auto t: popped){
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }

        }

        return res;
    }
};
