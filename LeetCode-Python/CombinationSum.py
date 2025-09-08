class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()  # pruning için
        res: List[List[int]] = []
        path: List[int] = []

        def dfs(start: int, remain: int) -> None:
            if remain == 0:
                res.append(path.copy())
                return
            for i in range(start, len(candidates)):
                val = candidates[i]
                if val > remain:
                    break  # sonraki değerler de daha büyük olur
                path.append(val)
                # aynı eleman sınırsız kullanılabildiği için i'yi tekrar gönderiyoruz
                dfs(i, remain - val)
                path.pop()

        dfs(0, target)
        return res
