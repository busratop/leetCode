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
    int maxDepth(TreeNode* root) {
    // Eğer kök düğüm boşsa, derinlik 0'dır 
    if (root == NULL) return 0; 
    // Sol ve sağ alt ağaçların derinliğini hesapla 
    int leftDepth = maxDepth(root->left); 
    int rightDepth = maxDepth(root->right); 
    // Daha büyük derinliği al ve 1 ekle 
    return max(leftDepth, rightDepth) + 1;
    }
};
