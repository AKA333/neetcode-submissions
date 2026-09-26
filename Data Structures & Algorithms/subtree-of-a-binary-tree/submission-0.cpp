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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)
            return 1;
        if(!root || !subRoot)
            return 0;
        if(root->val == subRoot->val){
            return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        }
        return 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot || !subRoot)
            return 1;
        if(!root)
            return 0;
        if(isSameTree(root, subRoot))
            return 1;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
