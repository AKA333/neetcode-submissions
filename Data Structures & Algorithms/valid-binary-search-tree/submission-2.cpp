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
#define ll long long
class Solution {
public:
    bool check(TreeNode* root, ll m, ll M){
        if(!root)
            return 1;
        if(root->val<=m || root->val >=M)
            return 0;
        return check(root->left, m, root->val) && check(root->right, root->val, M);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return 1;
        ll m= INT_MIN-(ll)1;
        ll M= INT_MAX+(ll)1;
        if(check(root, m, M) && isValidBST(root->left) && isValidBST(root->right))
            return 1;

        return 0;
    }
};
