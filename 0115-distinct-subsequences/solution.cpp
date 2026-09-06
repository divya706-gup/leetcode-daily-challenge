class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        // If t contains a character that s doesn't have,
        // answer is definitely 0.
        int cntS[256] = {};
        int cntT[256] = {};

        for (char c : s) cntS[c]++;
        for (char c : t) cntT[c]++;

        for (int i = 0; i < 256; i++) {
            if (cntT[i] > cntS[i]) {
                return 0;
            }
        }

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {

                if (s[i - 1] == t[j - 1]) {

                    if (dp[j - 1] > INT_MAX - dp[j]) {
                        dp[j] = INT_MAX;
                    }
                    else {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }

        return dp[m];
    }
};