class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
    long long lcml(long long a, long long b) { return (a / gcdll(a, b)) * b; }
    long long countCoins(long long x, vector<int>& coins, int k) {
        int n = coins.size();
        long long ans = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            long long lcm = 1;
            int bits = 0;
            bool overflow = false;
            for (int i = 0; i < n; i++) {
                if ((mask >> i) & 1) {
                    bits++;

                    long long g = gcdll(lcm, coins[i]);
                    if (lcm > x / (coins[i] / g)) {
                        overflow = true;
                        break;
                    }

                    lcm = lcm / g * coins[i];
                }
            }
                

            if (overflow) {
                continue;
            }
            long long cnt = x / lcm;
            if (bits % 2 == 1) {
                ans += cnt;
            } else {
                ans -= cnt;
            }
            
        }
        return ans;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (countCoins(mid, coins, k) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};