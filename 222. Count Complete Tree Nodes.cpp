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
    int count = 1;
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr) return count;
        if(root->right == nullptr) {           
            return ++count;
        }
        count += 2;
        countNodes(root->left);
        countNodes(root->right);
        return count;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = 0,rh = 0;
        TreeNode *l = root,*r = root;
        while(l != nullptr){
            l = l->left;
            ++lh;
        }       
        while(r != nullptr){
            r = r->right;
            ++rh;
        }
        if(lh == rh){
            return int(pow(2, lh) - 1);
        }
        return 1 + countNodes(root->left) + countNodes(root->right);  
    }     
};