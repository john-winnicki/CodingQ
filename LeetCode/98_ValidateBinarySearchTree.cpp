
class Solution {
public:
    bool validUtil(TreeNode* root, TreeNode* &prev){
        if(root==nullptr) return true;
        if(!validUtil(root->left, prev)){
            return false;
        }
        if(prev!=NULL && (root->val <= prev->val)) return false;
        prev = root;
        return validUtil(root->right, prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validUtil(root, prev);
    }
};