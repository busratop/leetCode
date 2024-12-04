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
    TreeNode* invertTree(TreeNode* root) {
        // Eğer kök düğüm boşsa, hiçbir işlem yapmadan geri dön 
        if (root == NULL) return NULL; 
        // Sol ve sağ çocukları tersine çevir 
        TreeNode* left = invertTree(root->left); 
        TreeNode* right = invertTree(root->right); 
        // Sol ve sağ çocukları değiştir 
        root->left = right; root->right = left; 
        return root;
    }
};
