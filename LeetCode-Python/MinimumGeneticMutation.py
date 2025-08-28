class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if startGene == endGene:
            return 0

        bank_set = set(bank)
        if endGene not in bank_set:
            return -1

        letters = "ACGT"
        q = deque([(startGene, 0)])
        visited = {startGene}

        while q:
            gene, steps = q.popleft()
            # Her pozisyonda tek harf değiştirerek komşu üret
            for i in range(8):
                original = gene[i]
                for c in letters:
                    if c == original:
                        continue
                    nxt = gene[:i] + c + gene[i+1:]
                    if nxt == endGene:
                        return steps + 1
                    if nxt in bank_set and nxt not in visited:
                        visited.add(nxt)
                        q.append((nxt, steps + 1))

        return -1
