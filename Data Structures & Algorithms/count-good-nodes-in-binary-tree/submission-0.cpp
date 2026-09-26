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
    void fn(TreeNode* root, int m, int &ans){
        if(!root)
            return ;
        ans++;
        if(root->val < m){
            ans-=1;
        }
        m= max(m, root->val);
        fn(root->left, m, ans);
        fn(root->right , m, ans);
    }
    int goodNodes(TreeNode* root) {
        int m= INT_MIN;
        int ans=0;

        fn(root, m, ans);
        return ans;
    }
    
};
