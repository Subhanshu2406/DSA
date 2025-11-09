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
    int res = 0;
    int goodNodes(TreeNode* root) {
        int maxVal = root -> val;
        dfs(root,maxVal);
        return res;
    }

    void dfs(TreeNode* root,int maxVal){
        if(root -> val >= maxVal) res++;
        maxVal = max(maxVal, root -> val);
        if(root -> left) dfs(root -> left,maxVal);
        if(root -> right) dfs(root -> right,maxVal);
    }
};