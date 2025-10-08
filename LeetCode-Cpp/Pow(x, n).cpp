class Solution {
public:
    double myPow(double x, int n) {
         // n'in long long olması, INT_MIN durumunda -n'in taşmasını engeller.
        long long N = n;
        double ans = 1.0;

        // Eğer n negatifse, x'i 1/x yaparız ve n'i pozitif hale getiririz.
        // Örneğin, x^-n = (1/x)^n
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        // İkili üs alma (binary exponentiation) algoritması
        while (N > 0) {
            // Eğer N tek ise, şu anki x değerini sonuca çarp.
            if (N % 2 == 1) {
                ans *= x;
            }
            // x'i kare al ve N'i yarıya böl.
            x *= x;
            N /= 2;
        }

        return ans;
    }
};
