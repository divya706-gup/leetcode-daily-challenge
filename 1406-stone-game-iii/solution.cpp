class Solution {
public:

    int solve(int i, vector<int>& stoneValue, vector<int>& dp) {

        int n = stoneValue.size();

        // No stones remaining
        if (i >= n)
            return 0;

        // Already calculated
        if (dp[i] != INT_MIN)
            return dp[i];

        int ans = INT_MIN;
        int sum = 0;

        // Current player can take 1, 2 or 3 stones
        for (int j = i; j < n && j < i + 3; j++) {

            sum += stoneValue[j];

            // My score - opponent's best score difference
            ans = max(ans, sum - solve(j + 1, stoneValue, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int diff = solve(0, stoneValue, dp);

        if (diff > 0)
            return "Alice";

        if (diff < 0)
            return "Bob";

        return "Tie";
    }
};