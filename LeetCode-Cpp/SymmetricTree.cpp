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
    bool isSymmetric(TreeNode* root) {
   // Kök düğüm boşsa, ağaç simetriktir 
   if (root == NULL) return true; 
   // Yardımcı fonksiyonu çağır 
   return isMirror(root->left, root->right); 
   } 
   bool isMirror(TreeNode* t1, TreeNode* t2) { 
    // Her iki düğüm de boşsa, aynıdırlar 
    if (t1 == NULL && t2 == NULL) return true; 
    // Biri boş, diğeri değilse, farklıdırlar 
    if (t1 == NULL || t2 == NULL) return false; 
    // Düğüm değerleri farklıysa, farklıdırlar 
    if (t1->val != t2->val) return false; 
    // Simetrik olup olmadığını kontrol et 
    return isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right); 
    }
};
