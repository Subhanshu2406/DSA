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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(check(root) == -1) return false;;
        return true;
    }

    int check(TreeNode* root){
        if(!root) return 0;
        int leftDepth = check(root -> left);
        int rightDepth = check(root -> right);
        if(leftDepth == -1 || rightDepth == -1) return -1;
        if(abs(leftDepth - rightDepth) > 1) return -1;
        return max(leftDepth,rightDepth) + 1;
    }
};