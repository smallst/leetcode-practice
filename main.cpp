/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    private:
    stack<TreeNode*> st;
public:
    void findLeft(TreeNode* root)
    {
        TreeNode * temp = root;
        while(temp!=NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
    }
    BSTIterator(TreeNode* root) {
        findLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode * head = st.top();
        int val = head->val;
        st.pop();
        if(head->right)
        {
            findLeft(head->right);
        }
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
