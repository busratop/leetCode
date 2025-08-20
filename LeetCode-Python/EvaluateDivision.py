class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
         # 1) Grafı kur: her kenarın tersi de eklenir
        graph: Dict[str, List[Tuple[str, float]]] = {}
        for (a, b), v in zip(equations, values):
            graph.setdefault(a, []).append((b, v))
            graph.setdefault(b, []).append((a, 1.0 / v))

        def dfs(src: str, dst: str) -> float:
            # src veya dst grafikte yoksa
            if src not in graph or dst not in graph:
                return -1.0
            # aynı değişkense ve tanımlıysa
            if src == dst:
                return 1.0

            visited = set([src])
            stack: List[Tuple[str, float]] = [(src, 1.0)]  # (node, çarpan)

            while stack:
                node, acc = stack.pop()
                if node == dst:
                    return acc
                for nei, w in graph.get(node, []):
                    if nei in visited:
                        continue
                    visited.add(nei)
                    stack.append((nei, acc * w))
            return -1.0

        # 2) Sorguları çöz
        return [dfs(c, d) for c, d in queries]
