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
    int maxPath(TreeNode* root, int &ans){
        if(!root)
            return 0;
        int l= max(0,maxPath(root->left, ans));
        int r= max(0, maxPath(root->right, ans));

        ans = max(ans, root->val+l+r);
        return max(l, r)+ root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int ans=INT_MIN;
        int t= maxPath(root, ans);
        // return max(t, ans);
        return ans;
    }
};
