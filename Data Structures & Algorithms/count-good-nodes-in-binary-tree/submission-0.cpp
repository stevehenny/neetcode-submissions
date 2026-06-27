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
    int count{};
    void dfs(TreeNode* node, int minimum){
        if(!node) return;

        if(node->val >= minimum) ++count;

        dfs(node->left, std::max(minimum, node->val));
        dfs(node->right, std::max(minimum, node->val));
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }
};
