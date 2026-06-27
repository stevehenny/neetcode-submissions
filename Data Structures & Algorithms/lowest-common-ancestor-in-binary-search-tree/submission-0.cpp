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
private:
    TreeNode* _p;
    TreeNode* _q;
    TreeNode* lca;
    // NOTE: If testcases allow duplicates this needs to change
    // This only checks the node values, assumes inputs are sanitized
    // and remove duplicates
   bool isContained(TreeNode* root, TreeNode* other){
    if(!root) return false;
    
    bool val = (root->val == other->val);
    return (val) ? val : isContained(root->left, other) || isContained(root->right, other);
   }

    void dfs(TreeNode* root){
        if(!root) return;

        if (isContained(root->left, _p) && isContained(root->left, _q)) lca = root->left;
        
        else if(isContained(root->right, _p) && isContained(root->right, _q)) lca = root->right;

        dfs(root->left);
        dfs(root->right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        _p = p;
        _q = q;
        lca = root;
        dfs(root);
        return lca;
    }
};
