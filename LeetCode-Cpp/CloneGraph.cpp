/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*, Node*> visited;
    Node* cloneGraph(Node* node) {
         if (node == nullptr)
            return nullptr;

        // If the node was already cloned, return it
        if (visited.find(node) != visited.end())
            return visited[node];

        // Clone the node (without neighbors for now)
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // Clone all the neighbors recursively
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};
