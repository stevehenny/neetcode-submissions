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
    bool status = true;
    int dfs(TreeNode* curr){
        if(!curr) return 0;

        int left = dfs(curr->left);
        int right = dfs(curr->right);

        status &= (abs(right - left) <= 1);
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return status;
    }
};
