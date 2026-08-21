class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long result = 0;

        // Inclusion-exclusion over all subsets
        for (int mask = 1; mask < (1 << n); mask++) {
            long long multiple = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;

                    multiple = lcm(multiple, coins[i]);

                    if (multiple > x) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (overflow)
                continue;

            long long cnt = x / multiple;

            if (bits % 2 == 1)
                result += cnt;
            else
                result -= cnt;
        }

        return result;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * coins[0] * k;

        for (int coin : coins)
            high = min(high, 1LL * coin * k);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};