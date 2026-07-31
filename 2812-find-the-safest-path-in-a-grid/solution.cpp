#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // If the start or end cell has a thief, the safeness factor is 0
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        // dist[r][c] will store the minimum Manhattan distance to any thief
        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Step 1: Initialize multi-source BFS from all thieves
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    q.push({r, c});
                    dist[r][c] = 0;
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Populate the distance matrix
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4;  ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        // Step 2: Use a Max-Priority Queue to find the maximum safeness path
        // Priority queue stores tuples of {safeness_factor, r, c}
        priority_queue<vector<int>> pq;
        vector<vector<int>> maxSafeness(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        maxSafeness[0][0] = dist[0][0];

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr[0];
            int r = curr[1];
            int c = curr[2];

            // If we reached the bottom-right corner, return its max safeness factor
            if (r == n - 1 && c == n - 1) {
                return d;
            }

            // If we found a better path to this cell already, skip
            if (d < maxSafeness[r][c]) continue;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    // The safeness of the path to the neighbor is limited 
                    // by the minimum safeness encountered so far
                    int nextSafeness = min(d, dist[nr][nc]);

                    if (nextSafeness > maxSafeness[nr][nc]) {
                        maxSafeness[nr][nc] = nextSafeness;
                        pq.push({nextSafeness, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};