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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result; 
        if (!root) return result; 
        deque<TreeNode*> nodeDeque; 
        nodeDeque.push_back(root); 
        bool leftToRight = true; 
        while (!nodeDeque.empty()) { 
            int size = nodeDeque.size(); 
            vector<int> level(size); 
            for (int i = 0; i < size; ++i) { 
                TreeNode* node; 
                if (leftToRight) { 
                    node = nodeDeque.front(); 
                    nodeDeque.pop_front(); 
                    if (node->left) nodeDeque.push_back(node->left); 
                    if (node->right) nodeDeque.push_back(node->right); 
                } 
                else { 
                        node = nodeDeque.back(); 
                        nodeDeque.pop_back(); 
                        if (node->right) nodeDeque.push_front(node->right); 
                        if (node->left) nodeDeque.push_front(node->left); } level[i] = node->val; 
                        } 
                        result.push_back(level); 
                        leftToRight = !leftToRight; 
                    } 
                return result;
    }
};
