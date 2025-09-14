"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: List[List[int]]) -> 'Node':
        n = len(grid)

        # Yardımcı fonksiyon: belirli alt kareden Quad-Tree düğümü oluşturur
        def build(x0, y0, length):
            # Alt kare tek tip mi?
            first_val = grid[x0][y0]
            all_same = True
            for i in range(x0, x0 + length):
                for j in range(y0, y0 + length):
                    if grid[i][j] != first_val:
                        all_same = False
                        break
                if not all_same:
                    break

            # Eğer tüm hücreler aynıysa -> Leaf Node
            if all_same:
                return Node(val=bool(first_val), isLeaf=True)

            # Karışık -> 4 parçaya böl
            half = length // 2
            return Node(
                val=True,        # fark etmez, True/False olabilir
                isLeaf=False,
                topLeft=build(x0, y0, half),
                topRight=build(x0, y0 + half, half),
                bottomLeft=build(x0 + half, y0, half),
                bottomRight=build(x0 + half, y0 + half, half)
            )

        return build(0, 0, n)
