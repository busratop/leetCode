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
// Ağacın derinliğini hesaplayan fonksiyon 
    int computeDepth(TreeNode* node) { 
        int depth = 0; while (node->left != NULL) { 
            node = node->left; depth++; 
            } return depth; 
        }
         // Belirtilen indeksin var olup olmadığını kontrol eden fonksiyon 
    bool exists(int index, int depth, TreeNode* node) { 
        int left = 0, right = pow(2, depth) - 1; 
        for (int i = 0; i < depth; i++) { 
            int mid = (left + right) / 2; 
            if (index <= mid) { 
                node = node->left; right = mid; 
                } else { 
                    node = node->right; left = mid + 1; 
                    } 
                    } 
                    return node != NULL; 
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0; 
        int depth = computeDepth(root); 
        if (depth == 0) return 1; 
        int left = 1, right = pow(2, depth) - 1; 
        while (left <= right) { 
            int mid = (left + right) / 2; 
            if (exists(mid, depth, root)) { 
                left = mid + 1; 
                } else { 
                    right = mid - 1; 
                    } 
        } 
        return pow(2, depth) - 1 + left;
    }
};
