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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) 
        { 
            inorder_map[inorder[i]] = i; 
        } 
        return build(preorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    private: 
    unordered_map<int, int> inorder_map; 
    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, int in_start, int in_end) 
    { 
        if (pre_start > pre_end || in_start > in_end) 
        { 
            return NULL;
        } 
        int root_val = preorder[pre_start]; 
        TreeNode* root = new TreeNode(root_val); 
        int in_root_idx = inorder_map[root_val]; 
        int nums_left = in_root_idx - in_start; 
        root->left = build(preorder, pre_start + 1, pre_start + nums_left, in_start, in_root_idx-1);
        root->right = build(preorder, pre_start + nums_left + 1, pre_end, in_root_idx + 1, in_end);
         return root; 
}
};
