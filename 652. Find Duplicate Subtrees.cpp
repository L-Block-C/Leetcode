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
    unordered_map <string, int> memo ; 
    vector<TreeNode*> dTree ;

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
          traverse(root);
          return dTree ;
    }

    string traverse( TreeNode* root){
        if(root == nullptr) return "#";
        string left = traverse(root->left);
        string right = traverse(root->right);

        string subtree = left + "," + right + "," + to_string(root->val)  ;

        if(memo[subtree] == 1) dTree.push_back(root);

        ++memo[subtree];

        return subtree;
    }
};