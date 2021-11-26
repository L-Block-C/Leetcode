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
    bool isValidBST(TreeNode* root) {
        return judge(root, LONG_MIN, LONG_MAX);
    }

    bool judge(TreeNode* root, long min, long max){
        if(root == nullptr) return true;
        if(root->val <= min || root->val >= max) return false;

        return judge(root->left, min, root->val) && judge(root->right, root->val, max);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return judge(root, nullptr, nullptr);
    }

    bool judge(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root == nullptr) return true;
        if(min && root->val <= min->val ) return false;
        if(max && root->val >= max->val) return false;
        return judge(root->left, min, root) && judge(root->right, root, max);
    }
};