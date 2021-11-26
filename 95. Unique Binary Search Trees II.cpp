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
    vector<vector<vector<TreeNode*>>> memo;
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        memo = vector<vector<vector<TreeNode*>>>(n + 1, vector<vector<TreeNode*>>(n+1));
        return build(1, n);
    }

    vector<TreeNode*> build(int a, int b){
        if(a > b) return {nullptr};
        if(!memo[a][b].empty()) return memo[a][b];

        for(int i = a; i <= b; ++i){
            vector<TreeNode*> left = build(a, i - 1);
            vector<TreeNode*> right = build(i + 1, b);
            for(auto ltree : left){
                for(auto rtree : right){
                    TreeNode* root = new TreeNode(i, ltree, rtree);
                    memo[a][b].push_back(root);
                }
            }
        }
        return memo[a][b];
    }
};