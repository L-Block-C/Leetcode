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
    int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        sum(root);
        return maxsum;
    }
    vector<int> sum(TreeNode* root){
        if(root == nullptr) return {1, INT_MAX, INT_MIN, 0};
        vector<int> rt(4);
        vector<int> left(4);
        vector<int> right(4);
        left = sum(root->left);
        right = sum(root->right);

        if(left[0] && right[0] && left[2] < root->val && right[1] > root->val){
            rt[0] = 1;
            rt[1] = min(root->val, left[1]);
            rt[2] = max(root->val, right[2]);
            rt[3] = root->val + left[3] + right[3];
            maxsum =  max(rt[3], maxsum);
        } else{rt[0] = 0;}
        return rt;

    }
};


class Solution {
public:
    int maxSum = 0;
    int maxSumBST(TreeNode* root) { 
        if(root == nullptr) return 0;      
        DFSmaxSum(root);
        return maxSum;
    }
    void DFSmaxSum(TreeNode* root) {
        if(root == nullptr)  return;
        if (isBST(root, INT_MIN, INT_MAX)) {
            GetSum(root);
            return;
        }
        DFSmaxSum(root->left);
        DFSmaxSum(root->right);
    }

    bool isBST(TreeNode* root, int min, int max) {
        if (root == nullptr) return true;
        return (min < root->val && root->val < max) &&
            isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }

    int GetSum(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = root->val + GetSum(root->left) + GetSum(root->right);
        maxSum = max(maxSum, res); // 更新最大和
        return res;
    }
};

/* 莫名其妙失败
class Solution {
public:
    int maxsum = 0;
    int maxSumBST(TreeNode* root) {
        if (root == nullptr) return 0;
        sum(root);
        return maxsum;
    }
    void sum(TreeNode* root){
        if(root == nullptr) return ;
        if(isBST(root, INT_MIN, INT_MAX)){
            maxsum = max(sumkey(root), maxsum);
        }
        sum(root->left);
        sum(root->right);
    }

    bool isBST(TreeNode*  root, int min, int max){
        if(root == nullptr) return true;
        if(root->val >max || root->val < min) return false;
        return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }
    int sumkey(TreeNode* root){
        if(root == nullptr) return 0;
        int left = sumkey(root->left);
        int right = sumkey(root->right);
        return root->val + left + right;
    }
};
*/

