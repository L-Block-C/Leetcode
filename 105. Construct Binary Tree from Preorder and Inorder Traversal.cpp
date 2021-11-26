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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0 , inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder , int pl , int pr,
                    vector<int>& inorder, int il, int ir){
        if(pl > pr) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        int index = 0;
        for(int i = il; i <= ir ; ++i){
            if(inorder[i] == preorder[pl]) {
                index = i;
                break;
            }
        }
        int len = index - il;
        root->left = build(preorder , pl + 1 , pl + len ,inorder ,il ,index - 1);
        root->right = build(preorder , pl+ len + 1 , pr ,inorder , index+1 , ir);

        return root;

    }
};