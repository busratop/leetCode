class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0

        n = len(prices)
        left = [0] * n  # 0..i arası en iyi işlem
        right = [0] * (n + 1)  # i..n-1 arası en iyi işlem

        # Soldan sağa: ilk işlem
        min_price = prices[0]
        for i in range(1, n):
            min_price = min(min_price, prices[i])
            left[i] = max(left[i - 1], prices[i] - min_price)

        # Sağdan sola: ikinci işlem
        max_price = prices[-1]
        for i in range(n - 1, -1, -1):
            max_price = max(max_price, prices[i])
            right[i] = max(right[i + 1], max_price - prices[i])

        # İki işlemi birleştir
        max_profit = 0
        for i in range(n):
            max_profit = max(max_profit, left[i] + right[i + 1])

        return max_profit
