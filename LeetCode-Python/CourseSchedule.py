class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # adjacency list ve indegree (giriş derecesi) tablosu
        adj = defaultdict(list)
        indeg = [0] * numCourses

        # kenarları kur
        for a, b in prerequisites:
            adj[b].append(a)
            indeg[a] += 1

        # indegree = 0 olan dersleri sıraya koy
        q = deque([i for i in range(numCourses) if indeg[i] == 0])

        taken = 0
        while q:
            u = q.popleft()
            taken += 1
            for v in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        # tüm dersler alınabilmişse True
        return taken == numCourses
