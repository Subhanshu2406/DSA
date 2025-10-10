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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root,targetSum});
        while(!stk.empty()){
            auto [curr, target] = stk.top();
            stk.pop();
            if(!curr -> right && !curr -> left && target == curr -> val) return true;
            if(curr -> right) stk.push({curr -> right, target - curr -> val});
            if(curr -> left) stk.push({curr -> left, target - curr -> val});
        }
        return false;
    }
};