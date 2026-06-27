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
    int helper(TreeNode* node){
        if (!node) return 0;
        int left = helper(node->left);
        int right = helper(node->right);
        int cur_path = node->val + std::max(left, right);
        return std::max(0, cur_path);
    }

    void dfs(TreeNode* node, int& res){
        if(!node) return;

        int left = helper(node->left);
        int right = helper(node->right);

        res = std::max(res, node->val + left + right);
        dfs(node->left, res);
        dfs(node->right, res);


    }
public:
    int maxPathSum(TreeNode* root) {
        int res{INT_MIN};
        dfs(root, res);
        return res;
    }
};
