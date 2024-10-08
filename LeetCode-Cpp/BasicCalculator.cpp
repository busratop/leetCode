class Solution {
public:
    int calculate(string s) {
        stack<int> nums;  // sayıları tutacak yığın
        stack<char> ops;  // operatörleri tutacak yığın
        int num = 0;
        int result = 0;
        int sign = 1;  // '+' işareti için başlangıçta pozitif

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');  // sayıyı birleştir
            } else if (c == '+' || c == '-') {
                result += sign * num;  // bir önceki sayıyı işaretine göre ekle
                num = 0;               // yeni sayıya başla
                sign = (c == '+') ? 1 : -1;  // işareti güncelle
            } else if (c == '(') {
                // parantez açıldığında önceki sonucu ve işareti kaydet
                nums.push(result);
                ops.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;  // iç parantezdeki sonucu hesapla
                num = 0;
                result *= ops.top();  // işareti uygula
                ops.pop();
                result += nums.top();  // önceki sonucu ekle
                nums.pop();
            }
        }
        result += sign * num;  // son kalan sayıyı ekle
        return result;
        }
};
