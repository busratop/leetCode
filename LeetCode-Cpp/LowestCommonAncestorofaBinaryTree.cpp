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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Temel Durum: Eğer root NULL ise veya root, p ya da q ise 
        if (root == NULL || root == p || root == q) { 
            return root; 
        } 
        // Sol ve Sağ Alt Ağaçlarda Rekürsif Arama 
        TreeNode* left = lowestCommonAncestor(root->left, p, q); 
        TreeNode* right = lowestCommonAncestor(root->right, p, q); 
        // Eğer hem left hem de right NULL değilse, root en düşük ortak atadır 
        if (left != NULL && right != NULL) { 
            return root; 
        } // Aksi takdirde, NULL olmayan değeri döndür 
        return left != NULL ? left : right;
    }
};
