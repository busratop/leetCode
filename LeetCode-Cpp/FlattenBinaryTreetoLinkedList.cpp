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
    void flatten(TreeNode* root) {

        if (!root) return;

        stack<TreeNode*> stack;
        stack.push(root);

        TreeNode* prev = nullptr;

        while (!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();

            if (prev) {
                prev->right = curr;
                prev->left = nullptr;
            }

            if (curr->right) {
                stack.push(curr->right);
            }
            if (curr->left) {
                stack.push(curr->left);
            }

            prev = curr;

}

    }
};
