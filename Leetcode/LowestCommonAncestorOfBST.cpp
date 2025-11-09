/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//for an arbitrary tree:
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q).second;
    }

    pair<int,TreeNode*> dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return {0,nullptr};
        pair<int,TreeNode*> foundLeft = dfs(root -> left , p, q);
        pair<int,TreeNode*> foundRight = dfs(root -> right , p, q);
        if(foundLeft.first == 2) return foundLeft;
        if(foundRight.first == 2) return foundRight;
        if(foundLeft.first + foundRight.first == 2) return {2,root};

        if(root -> val == p -> val || root -> val == q -> val) return {foundLeft.first + foundRight.first + 1, root};
        return {foundLeft.first + foundRight.first, nullptr};
    }
};

//for a bst
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal = p -> val;
        int qVal = q -> val;
        int high = max(pVal,qVal);
        int low = min(pVal,qVal);
        return dfs(root,high,low);
    }

    TreeNode* dfs(TreeNode* root,int high, int low){
        if(!root) return nullptr;
        if(root -> val >= low && root -> val <= high) return root;
        else if(root -> val > high) return dfs(root -> left, high,low);
        else if(root -> val < low) return dfs(root -> right,high,low);
        return nullptr;
    }
};