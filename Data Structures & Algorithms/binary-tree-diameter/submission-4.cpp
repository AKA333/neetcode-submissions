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
    // int ans=0;
    int fn(TreeNode* root, int &ans){
        if(!root)
            return 0;
        int l= fn(root->left, ans);
        int r= fn(root->right, ans);

        ans = max(ans, l+r);
        // cout<<ans<<" ";
        return 1+ max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        fn(root, ans);
        return ans;
    }
};
