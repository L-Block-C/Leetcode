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
   TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0 , postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder , int il , int ir,
                    vector<int>& postorder, int pl, int pr){
        if(il > ir) return nullptr;
        TreeNode* root = new TreeNode(postorder[pr]);
        int index = 0;
        for(int i = il; i <= ir ; ++i){
            if(inorder[i] == postorder[pr]) {
                index = i;
                break;
            }
        }
        int len = index - il;
        root->left = build(inorder , il , index - 1,postorder ,pl ,pl + len - 1);
        root->right = build(inorder , index + 1 , ir ,postorder , pl + len , pr - 1);

        return root;

    }
};