class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        using iter = std::vector<int>::iterator;
        using stack_entry = std::tuple<TreeNode**, std::pair<iter, iter>, std::pair<iter, iter>>;

        auto stack = std::stack<stack_entry>();
        TreeNode * root = nullptr;
        stack.emplace(
            &root,
             std::pair(inorder.begin(), inorder.end()),
             std::pair(postorder.begin(), postorder.end())
        );
        while (!stack.empty()) {
            auto [parents_link, in, post] = stack.top();
            stack.pop();
            if (in.first == in.second)
                continue;

            auto * node = new TreeNode(*std::prev(post.second));
            *parents_link = node;
            const int nodes_in_left_subtree = 
                std::distance(in.first, std::find(in.first, in.second, node->val));

            stack.emplace(
                &node->left,
                std::pair(in.first, in.first + nodes_in_left_subtree),
                std::pair(post.first, post.first + nodes_in_left_subtree)
            );
            stack.emplace(
                &node->right,
                std::pair(in.first + nodes_in_left_subtree + 1, in.second),
                std::pair(post.first + nodes_in_left_subtree, std::prev(post.second))
            );
        }
        return root;
    }
};
