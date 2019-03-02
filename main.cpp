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
    int kthSmallest(TreeNode* root, int k) {
        int l = countNodes(root->left);
        if(l + 1 == k)
            return root->val;
        else if(l + 1< k)
            return kthSmallest(root->right, k-l-1);
        else
            return kthSmallest(root->left, k);
    }
    
    int countNodes(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return countNodes(root->left) + 1 + countNodes(root->right);
    }
};
