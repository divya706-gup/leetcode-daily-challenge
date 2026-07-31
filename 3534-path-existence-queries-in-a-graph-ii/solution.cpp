#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // Pairs of {value, original_index}
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());

        // Map original index to sorted position index
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[sorted_nodes[i].second] = i;
        }

        // Compute the connected component IDs
        vector<int> comp(n, 0);
        int curr_comp = 0;
        for (int i = 1; i < n; ++i) {
            if (sorted_nodes[i].first - sorted_nodes[i - 1].first > maxDiff) {
                curr_comp++;
            }
            comp[i] = curr_comp;
        }

        // Binary Jumping Setup
        int max_log = log2(n) + 2;
        vector<vector<int>> dp(max_log, vector<int>(n));

        // Base case: 2^0 = 1 step
        // For each node i, find the largest j such that nums[j] - nums[i] <= maxDiff
        int r = 0;
        for (int i = 0; i < n; ++i) {
            while (r < n && sorted_nodes[r].first - sorted_nodes[i].first <= maxDiff) {
                r++;
            }
            dp[0][i] = r - 1; // Farthest index reachable in 1 step
        }

        // Fill sparse table
        for (int k = 1; k < max_log; ++k) {
            for (int i = 0; i < n; ++i) {
                dp[k][i] = dp[k - 1][dp[k - 1][i]];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            // Ensure u is to the left of v in sorted order
            if (u > v) swap(u, v);

            // If they are not in the same connected component, no path exists
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            // Count the steps using binary jumping
            int steps = 0;
            int curr = u;
            for (int k = max_log - 1; k >= 0; --k) {
                if (dp[k][curr] < v) {
                    steps += (1 << k);
                    curr = dp[k][curr];
                }
            }
            
            // One final step to cross or reach v
            ans.push_back(steps + 1);
        }

        return ans;
    }
};