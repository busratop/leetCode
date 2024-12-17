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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;

        int totalSum = 0;
        int currentSum = 0;
        
        // Lambda fonksiyonu ile rekürsif hesaplama
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int currentSum) {
            if (!node) return;

            currentSum = currentSum * 10 + node->val;

            // Yaprak düğüme ulaşıldığında toplamı güncelle
            if (!node->left && !node->right) {
                totalSum += currentSum;
                return;
            }

            // Sol ve sağ çocukları ziyaret et
            dfs(node->left, currentSum);
            dfs(node->right, currentSum);
        };

        dfs(root, currentSum);
        return totalSum;


    }
};
