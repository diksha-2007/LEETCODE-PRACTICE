
class Solution {
public:
    int preimageSizeFZF(int k) {
        long long left = 0, right = 5LL * (k + 1);

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long n = mid;
            long long count = 0;

            while (n > 0) {
                n = n / 5;
                count = count + n;
            }

            if (count == k) {
                return 5;
            }
            else if (count < k) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return 0;
    }
};