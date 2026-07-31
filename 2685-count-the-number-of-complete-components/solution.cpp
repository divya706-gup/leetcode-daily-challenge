class Solution {
public:
    void dfs(int node,const vector<vector<int>>&adj,vector<bool>&visited,int &nodeCount,int &edgeCount){
        visited[node] = true;
        nodeCount++;
        edgeCount +=adj[node].size();
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                dfs(neighbor,adj,visited,nodeCount,edgeCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int edgeCount=0;
                int nodeCount=0;
                dfs(i,adj,visited,nodeCount,edgeCount);
                int actualEdges=edgeCount/2;
                int expectedEdges=(nodeCount*(nodeCount-1))/2;
                if(actualEdges==expectedEdges){
                    ans++;
                }
            }
        }
        return ans;
    }
};