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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        _leftmost_inorder(root);
    }
    
    int next() {
        TreeNode* topmostNode = stack_.top(); 
        stack_.pop(); 
        if (topmostNode->right != NULL) 
        { _leftmost_inorder(topmostNode->right); } 
        return topmostNode->val;
    }
    
    
    bool hasNext() {
        return !stack_.empty();
    }
    private: 
    stack<TreeNode*> stack_; 
    void _leftmost_inorder(TreeNode* node) { 
        while (node != NULL) 
    { 
        stack_.push(node); node = node->left;
     } 
     }

    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
