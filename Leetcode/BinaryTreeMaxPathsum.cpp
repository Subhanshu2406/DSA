// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int res = INT_MIN;
//     int maxPathSum(TreeNode* root) {
//         dfs(root);
//         return res;
//     }

//     int dfs(TreeNode* root){
//         if(!root) return 0;

//         int leftSum;
//         int rightSum;
//         if(root -> left) {
//             leftSum = dfs(root -> left);
//             res = max(res, leftSum);
//         }
//         if(root -> right) {
//             rightSum = dfs(root -> right);
//             res = max(res, rightSum);
//         }

//         if(root -> left && root -> right){
//             res = max(res, rightSum + leftSum + root -> val);
//         }

//         res = max(res, root -> val);

//         if(root -> left && root -> right && leftSum > rightSum && leftSum > 0) return root -> val + leftSum;
//         else if(root -> left && root -> right && leftSum < rightSum && rightSum > 0) return root -> val + rightSum;
//         else if(root -> left && leftSum > 0) return root -> val + leftSum;
//         else if(root -> right && rightSum > 0) return root -> val + rightSum;
//         return root -> val;
//     }
// };


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
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int leftSum = dfs(root -> left);
        int rightSum = dfs(root -> right);

        if(leftSum == 0 && rightSum == 0){
            res = max(res, root -> val);
            return root -> val;
        }

        else if(leftSum == 0){
            res = max(res, max(root -> val, max(root -> val + rightSum, rightSum)));
            return max(root -> val, root -> val + rightSum);
        }
        else if(rightSum == 0){
            res = max(res, max(root -> val, max(root -> val + leftSum, leftSum)));
            return max(root -> val, root -> val + leftSum);
        }


        res = max(res,max(max(max(leftSum,leftSum + root -> val), max(rightSum, rightSum + root -> val)),leftSum + rightSum + root -> val));
        res = max(res, root->val);
        
        if(max(leftSum,rightSum) > 0) return root -> val + max(leftSum, rightSum);
        return root -> val;
    }
};