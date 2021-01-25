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
    int maxPathSum(TreeNode* root) {
        int currmax = INT_MIN;
        maxUtil(root, currmax);
        return currmax;
    }
    int maxUtil(TreeNode* root, int& currmax){
        if(root==nullptr) return 0;
        int left = maxUtil(root->left, currmax);
        int right = maxUtil(root->right, currmax);
        int combine = (left>0 ? left : 0) + root->val + (right>0 ? right : 0);
        currmax = max(currmax, combine);
        return max(max(left, right), 0)+root->val;
    }
};