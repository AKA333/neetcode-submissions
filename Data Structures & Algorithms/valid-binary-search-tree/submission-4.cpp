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
    bool check(TreeNode* root, int m, int M){
        if(!root)
            return 1;
        if(root->val <=m || root->val >=M)
            return 0;
        return check(root->left, m, root->val) && check(root->right, root->val, M);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return 1;
        int m= INT_MIN;
        int M= INT_MAX;

        return check(root, m, M);
    }
};
