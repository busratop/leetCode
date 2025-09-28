class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = []
        i, j = len(a) - 1, len(b) - 1
        carry = 0

        while i >= 0 or j >= 0 or carry:
            current_sum = carry

            if i >= 0:
                current_sum += int(a[i])
                i -= 1
            if j >= 0:
                current_sum += int(b[j])
                j -= 1

            result.append(str(current_sum % 2))
            carry = current_sum // 2

        return "".join(result[::-1]) # Sonucu ters çevirip birleştir
