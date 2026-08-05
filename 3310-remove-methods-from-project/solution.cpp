class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        vector<vector<int>> adj(n);
        
        for (auto &it : invocations) {
            adj[it[0]].push_back(it[1]);
        }

        vector<bool> suspicious(n, false);
        queue<int> q;
        
        q.push(k);
        suspicious[k] = true;

        // Find all methods reachable from k
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : adj[node]) {
                if (!suspicious[next]) {
                    suspicious[next] = true;
                    q.push(next);
                }
            }
        }

        // Check if any non-suspicious method
        // invokes a suspicious method
        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};