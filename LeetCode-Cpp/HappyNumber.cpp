class Solution {
public:
    bool isHappy(int n) {
       while(true) {
            long long int num = 0;
            if(n < 10) {
                if(n == 1 || n == 7)
                    return true;
                else
                    return false;
            }
            while(n) {
                num += pow(n%10, 2);
                n /= 10;
            }
            n = num;
        }
        return false;
    }
};
