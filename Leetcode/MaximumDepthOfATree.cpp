//we can use dfs on this till we reach a node which has no roots and then return back 
//we will do pre order dfs (left -> right) [center doesnt matter as its obvious it has nodes]
//store the depth in some variable and keep passing it along with the max depth encountered so far
//we will update maxdepth only when we reach a node with no further nodes and update acc and return maxdepth

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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        int maxdepth = 0;
        if(!root) return 0;
        return find(root, depth, maxdepth);
    }

    int find(TreeNode* root, int depth,int maxdepth){
        depth++;
        if(!root -> right && !root -> left) return max(maxdepth,depth); 

        if(root -> left) maxdepth = find(root -> left, depth,maxdepth);
        if(root -> right) maxdepth = find(root -> right,depth, maxdepth);
        return maxdepth;
    }
};

//using iterative DFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode* , int>> current;
        int max = 0;
        current.push({root,1});
        if(!root) return 0;

        while(!current.empty()){
            TreeNode* topNode = current.top().first;
            int depth = current.top().second;
            current.pop();

            if(topNode -> right) current.push({topNode -> right, depth + 1});
            if(topNode -> left) current.push({topNode -> left, depth + 1});
            max = max(max,depth);
        }
        return max;
    }
};