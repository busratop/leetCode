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
    int getMinimumDifference(TreeNode* root) {
        // Önceki düğüm değerini saklamak için bir değişken 
        int prev = -1; 
        // Minimum farkı saklamak için bir değişken 
        int minDiff = INT_MAX; 
        // Ağaçta dolaşan yardımcı fonksiyon 
        inorderTraversal(root, prev, minDiff); 
        return minDiff;
    }
private: 
    void inorderTraversal(TreeNode* node, int& prev, int& minDiff) { 
        if (!node) return; 
        // Sol alt ağacı dolaş 
        inorderTraversal(node->left, prev, minDiff); 
        // Eğer önceki düğüm değeri varsa, minimum farkı güncelle 
        if (prev != -1) { 
            minDiff = min(minDiff, node->val - prev); 
        } 
        // Şu anki düğüm değerini önceki düğüm değeri olarak ayarla 
        prev = node->val; 
        // Sağ alt ağacı dolaş 
        inorderTraversal(node->right, prev, minDiff); }
};
