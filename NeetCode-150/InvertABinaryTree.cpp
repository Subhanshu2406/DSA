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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        inside(root);
        return root;

    }

    TreeNode* inside(TreeNode* root){
        if(root -> right == nullptr && root -> left == nullptr) return root;

        TreeNode* r = root -> right;
        TreeNode* l = root -> left; 
        root -> right = l;
        root -> left = r;

        if(root -> right) inside(root -> right);
        if(root -> left) inside(root -> left);
        return root;
    }
};
