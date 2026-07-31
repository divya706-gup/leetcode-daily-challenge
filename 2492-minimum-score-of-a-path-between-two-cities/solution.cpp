class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Step 1: Build an adjacency list for the undirected graph
        // Each entry stores a pair: {neighbor, road_cost}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int cost = road[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost}); // Since roads are bidirectional
        }

        // Step 2: BFS to find the minimum edge score in city 1's connected component
        int min_score = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;

        q.push(1);
        visited[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int cost = edge.second;

                // Track the absolute minimum edge cost seen in this component
                min_score = min(min_score, cost);

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return min_score;
    }
};