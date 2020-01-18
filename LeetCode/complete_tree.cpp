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
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL)
            return true;
        queue<TreeNode*> q;
        bool end = false;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left && end)
                return false;
            else if (temp->left && !end)
                q.push(temp->left);
            else
                end = true;
            if (temp->right && end)
                return false;
            else if (temp->right)
                q.push(temp->right);
            else
                end = true;
        }
        return true;
    }
};