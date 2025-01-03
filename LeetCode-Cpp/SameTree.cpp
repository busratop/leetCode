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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Her iki düğüm de boşsa, ağaçlar aynıdır 
        if (p == NULL && q == NULL) return true; 
        // Biri boş, diğeri değilse, ağaçlar farklıdır 
        if (p == NULL || q == NULL) return false; 
        // Düğüm değerleri farklıysa, ağaçlar farklıdır 
        if (p->val != q->val) return false; 
        // Sol ve sağ alt ağaçları karşılaştır 
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
