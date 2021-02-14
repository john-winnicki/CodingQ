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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // cout<<preorder[0]<<endl;
        if(preorder.size()==0) return nullptr;
        if(preorder.size()==1) return new TreeNode(preorder[0]);
        int inorder_pos = 0;
        while(inorder[inorder_pos]!=preorder[0]) inorder_pos++;
        // cout<<inorder_pos<<endl;
        vector<int> npre_before = vector<int>(preorder.begin()+1, preorder.begin()+inorder_pos+1);
        // cout<<npre_before[0]<<endl;
        vector<int> npre_after = vector<int>(preorder.begin()+inorder_pos+1, preorder.end());
        // cout<<npre_after[0];
        vector<int> nin_before = vector<int>(inorder.begin(), inorder.begin()+inorder_pos);
        // cout<<nin_before[0];
        vector<int> nin_after = vector<int>(inorder.begin()+inorder_pos+1, inorder.end());
        // cout<<nin_after[0];
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = buildTree(npre_before, nin_before);
        root->right = buildTree(npre_after, nin_after);
        return root;
    }
};