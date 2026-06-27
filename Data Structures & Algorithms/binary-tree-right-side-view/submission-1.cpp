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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;

        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            bool rightMost = false;
            // get the right most node;
            vector<TreeNode*> popped;
            while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
        
            if(!rightMost){ 
                ret.push_back(temp->val);
                rightMost = true;
                } 
        
            popped.push_back(temp);
            }
         
            for(auto t: popped){
                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);
            }

        }

        return ret;
    }
};
