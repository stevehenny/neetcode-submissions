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

class Codec {
private:
    void dfs_serialize(TreeNode* node, std::string& output){
        if(node->left){
            output += '#';
            output += std::to_string(node->left->val);
            dfs_serialize(node->left, output);
        }
        else{
            output += '.';
        }
        if(node->right){
            output += '#';
            output += std::to_string(node->right->val);
            dfs_serialize(node->right, output);
        }
        else{
            output += '.';
        }
    }

    void dfs_deserialize(std::string& cur_string, TreeNode* cur_node, int& cur_ind){
        if(cur_ind == cur_string.length()) return;
        std::cout << cur_string[cur_ind];

        if(cur_string[cur_ind] == '#'){
            string cur_num;
            int i{cur_ind + 1};
            while(isdigit(cur_string[i])){
                cur_num += cur_string[i];
                ++i;
            }
            cur_ind = i;
            cur_node->left = new TreeNode(std::stoi(cur_num));
            
            dfs_deserialize(cur_string, cur_node->left, cur_ind);
        }
        else{
            cur_ind++;
            cur_node->left = nullptr;
        }

        // handle right tree
        if(cur_string[cur_ind] == '#'){
            string cur_num;
            int i{cur_ind + 1};
            while(isdigit(cur_string[i])){
                cur_num += cur_string[i];
                ++i;
            }
            cur_ind = i;
            cur_node->right = new TreeNode(std::stoi(cur_num));
            dfs_deserialize(cur_string, cur_node->right, cur_ind);
        }
        else{
            cur_ind++;
            cur_node->right = nullptr;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string output;
        if(!root) return output;
        output += '#';
        output += std::to_string(root->val);
        dfs_serialize(root, output);
        return output;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;

        int cur_ind{1}; 
        string cur_num;
        TreeNode* root;
        while(isdigit(data[cur_ind])){
            cur_num += data[cur_ind];
            ++cur_ind;
        }
        root = new TreeNode(std::stoi(cur_num));
        dfs_deserialize(data, root, cur_ind);
        return root;
    }
};
