class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
         # Graf: b -> a (a'yı almak için önce b)
        adj = defaultdict(list)
        indeg = [0] * numCourses

        for a, b in prerequisites:
            adj[b].append(a)
            indeg[a] += 1

        # Önkoşulu olmayan dersler kuyruğa
        q = deque([i for i in range(numCourses) if indeg[i] == 0])
        order = []

        while q:
            u = q.popleft()
            order.append(u)
            for v in adj[u]:
                indeg[v] -= 1
                if indeg[v] == 0:
                    q.append(v)

        # Tüm dersler eklendiyse geçerli sıra, yoksa döngü var -> boş liste
        return order if len(order) == numCourses else []
