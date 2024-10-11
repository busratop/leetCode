class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        current_number = 0
        result = 0
        sign = 1  # 1: pozitif, -1: negatif

        for char in s:
            if char.isdigit():
                current_number = current_number * 10 + int(char)  # Sayıyı oluştur
            elif char in "+-":
                result += sign * current_number  # Geçerli sayıyı sonuçla ekle
                current_number = 0  # Sayıyı sıfırla
                sign = 1 if char == '+' else -1  # İşlemi güncelle
            elif char == '(':
                stack.append(result)  # Geçerli sonucu yığının üstüne ekle
                stack.append(sign)  # İşlemi yığının üstüne ekle
                result = 0  # Sonucu sıfırla
                sign = 1  # Yeni alt ifade için işaret sıfırla
            elif char == ')':
                result += sign * current_number  # Geçerli sayıyı ekle
                current_number = 0  # Sayıyı sıfırla
                result *= stack.pop()  # İşaretin etkisini uygula
                result += stack.pop()  # Yığından önceki sonucu ekle

        # En son sayıyı ekle
        result += sign * current_number
        return result
