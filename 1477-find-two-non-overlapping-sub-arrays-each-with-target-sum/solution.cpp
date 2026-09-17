class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF=1e9;
        vector<int> prefix(n,INF);
        vector<int> suffix(n,INF);
        int left = 0;
        long long sum = 0;
        int best = INF;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int len = i - left + 1;
                best = min(best, len);
            }
            prefix[i] = best;
        }
        left = 0;
        sum = 0;
        best = INF;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int len = i - left + 1;
                suffix[left] = min(suffix[left], len);
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(suffix[i], suffix[i + 1]);
        }
        int ans = INF;
        for (int i = 1; i < n; i++) {
            if (prefix[i - 1] != INF && suffix[i] != INF) {
                ans = min(ans, prefix[i - 1] + suffix[i]);
            }
        }
        return ans == INF ? -1 : ans;
    }
};