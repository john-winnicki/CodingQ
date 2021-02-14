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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> myq;
        vector<vector<int>> fin;
        if(root==nullptr) return fin;
        myq.push(root);
        while(!myq.empty()){
            int size = myq.size();
            vector<int> temp;
            for(int i = 0; i<size; i++){
                TreeNode* node = myq.front();
                myq.pop();
                temp.push_back(node->val);
                if(node->left!=nullptr) myq.push(node->left);
                if(node->right!=nullptr) myq.push(node->right);
            }
            fin.push_back(temp);
        }
        return fin;
    }
};