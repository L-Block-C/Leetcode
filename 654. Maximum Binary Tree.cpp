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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructNode(nums, 0, nums.size()-1);
    }
    TreeNode* constructNode(vector<int>& nums, int l ,int h){
        if(l > h) return nullptr;
        int index = -1, maxval = -1;       
        for(int i = l; i<=h ; ++i){
            if (nums[i] > maxval){
                maxval = nums[i];
                index = i;
            }
        }

        TreeNode* root = new TreeNode(maxval);

        root->left = constructNode(nums, l ,index -  1);
        root->right = constructNode(nums, index + 1 ,h);

        return root;
    }
};