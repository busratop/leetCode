lass Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
      max_candies = max(candies)  # En fazla şeker sayısını bul
      result = []

      for kid_candies in candies:
          if kid_candies + extraCandies >= max_candies:
              result.append(True)
          else:
              result.append(False)

      return result
