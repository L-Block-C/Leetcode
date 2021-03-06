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

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;

        if(root->val == val)
            return root;
        if (root->val > val){
            return searchBST(root->left, val);
        }
        if(root->val < val){
            return searchBST(root->right ,val);
        }
        return nullptr;
    }
};

class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val){
            return root;
        }
        return (root->val > val) ? searchBST(root->left,val) : searchBST(root->right,val);
    }
};

class Solution {
public:

    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr && root->val != val){
            root = (root->val > val) ? root->left :root->right;
        }
        return root;
    }
};