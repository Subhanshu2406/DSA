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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* curr = root;

        while(curr || !stk.empty()){
            if(curr){
                res.push_back(curr -> val);
                stk.push(curr);
                curr = curr -> right;
            }    
            else{
                curr = stk.top();
                stk.pop();
                curr = curr -> left;
            }
        }

        reverse(res.begin(),res.end());
        return res;
    }
};