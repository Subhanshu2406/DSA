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

 //when finding the longest part, we can be sure that the 2 ends are leaf(no child nodes)
 //we will do post order DFS, here we will implement it via recursion
 //at a particular node, we will get the deepest left and right node and calculate the distance between them
 //then update maxSum if distance was greater than present maxSum.
class Solution {
public:
    int maxPath = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        distance(root, height);
        return maxPath;

    }

    int distance(TreeNode* root, int height){
        if(!root) return height;
        height++;
        int leftDepth = distance(root -> left, height);
        int rightDepth = distance(root -> right, height); 
        int pathDis = (leftDepth - height) + (rightDepth - height) + 1;
        maxPath = max(maxPath, pathDis);
        return max(rightDepth, leftDepth);
    }
};