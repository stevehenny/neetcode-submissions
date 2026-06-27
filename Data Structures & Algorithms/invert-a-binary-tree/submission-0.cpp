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
    void helper(TreeNode* root){
        if(root->left) helper(root->left);
        if(root->right) helper(root->right);

        std::swap(root->left, root->right);
        
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        helper(root);
        return root;
    }
};
