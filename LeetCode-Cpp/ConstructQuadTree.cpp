/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
    
private:
    Node* build(vector<vector<int>>& grid, int x0, int y0, int length) {
        // İlk hücreyi referans al
        int first_val = grid[x0][y0];
        bool all_same = true;
        
        // Bu alt-karedeki tüm değerler aynı mı?
        for (int i = x0; i < x0 + length; i++) {
            for (int j = y0; j < y0 + length; j++) {
                if (grid[i][j] != first_val) {
                    all_same = false;
                    break;
                }
            }
            if (!all_same) break;
        }
        
        // Eğer tüm hücreler aynıysa -> yaprak
        if (all_same) {
            return new Node(first_val == 1, true);
        }
        
        // Karışık -> 4 parçaya böl
        int half = length / 2;
        Node* topLeft = build(grid, x0, y0, half);
        Node* topRight = build(grid, x0, y0 + half, half);
        Node* bottomLeft = build(grid, x0 + half, y0, half);
        Node* bottomRight = build(grid, x0 + half, y0 + half, half);
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
