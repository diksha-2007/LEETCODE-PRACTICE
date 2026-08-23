class Solution {
public:
    int reverse(int x) {
        long long rev = 0;

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        if (rev < -2147483648LL || rev > 2147483647LL) {
            return 0;
        }

        return (int)rev;
    }
};