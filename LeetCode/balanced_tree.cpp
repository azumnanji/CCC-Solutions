/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool end = false;
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        recur(root);
        if (end == false)
            return true;
        return false;
    }
    
    void recur(TreeNode* root){
        if (root == NULL || end)
            return;
        recur(root->left);
        recur(root->right);
        if (abs(height(root->left) - height(root->right)) > 1 )
            end = true;
    }
    
    int height(TreeNode* root){
        if (root == NULL)
            return -1;
        else
            return 1 + max(height(root->left), height(root->right));
    }
};