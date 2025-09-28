class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0'; // Karakteri int'e dönüştür
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Karakteri int'e dönüştür
                j--;
            }

            result += to_string(sum % 2); // Toplamın son bitini ekle
            carry = sum / 2;             // Yeni carry değerini hesapla
        }

        reverse(result.begin(), result.end()); // Sonucu ters çevir
        return result;
    }
};
