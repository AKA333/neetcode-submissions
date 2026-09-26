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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root= new TreeNode(preorder[ps]);
        int id;
        for(int i=is; i<=ie; i++){
            if(preorder[ps] == inorder[i]){
                id= i;
                break;
            }
        }
        int l= id-is;
        root->left = build(preorder, inorder, ps+1, ps+l, is, id-1);
        root->right = build(preorder, inorder, ps+l+1, pe, id+1, ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n= preorder.size();
        int ps=0, pe= n-1;
        int is=0, ie= n-1;

        auto root = build(preorder, inorder, ps, pe, is, ie);
        return root;
    }
};
