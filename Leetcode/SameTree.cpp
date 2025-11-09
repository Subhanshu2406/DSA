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

 //we will use recursive dfs
 //we do recursive dfs on p and q toegether and if any value isnt same we return false
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p,q);
    }   

    bool compare(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        else if(!p || !q) return false;

        if(p -> val != q -> val) return false;
        
        bool first = compare(p -> left,q -> left);
        bool second = compare(p -> right,q -> right);
        if(first && second) return true;
        return false;

    }
};