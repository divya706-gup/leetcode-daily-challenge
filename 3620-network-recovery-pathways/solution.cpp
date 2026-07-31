class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(); // Fixed: changed .length to .size()
        vector<vector<pair<int, int>>> adj(n);
        vector<int> inDegree(n, 0);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj[u].push_back({v, cost});
            inDegree[v]++;
        }

        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                int v = edge.first;
                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        auto check = [&](int mid) -> bool {
            vector<long long> dist(n, 1e16);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == 1e16) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    int cost = edge.second;
                    if (cost >= mid) {
                        if (dist[u] + cost < dist[v]) {
                            dist[v] = dist[u] + cost;
                        }
                    }
                }
            }
            return dist[n - 1] <= k;
        };

        int low = 0, high = 1e9, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};