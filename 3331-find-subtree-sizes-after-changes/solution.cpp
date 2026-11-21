class Solution {
public:
    vector<vector<int>> originalTree, newTree;
    vector<int> ans;
    int last[26];
    void dfs(int u, vector<int>& parent, string& s) {
        int ch = s[u] - 'a';
        int prev = last[ch];
        if (u != 0) {
            int newParent;
            if (prev != -1) {
                newParent = prev;
            } else {
                newParent = parent[u];
            }
            newTree[newParent].push_back(u);
        }
        last[ch] = u;
        for (int v : originalTree[u]) {
            dfs(v, parent, s);
        }
        last[ch] = prev;
    }
    int find(int u) {
        int s = 1;
        for (int v : newTree[u]) {
            s += find(v);
        }
        ans[u] = s;
        return s;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        originalTree.resize(n);
        newTree.resize(n);
        ans.resize(n, 0);
        fill(last, last + 26, - 1);
        for (int i = 1; i < n; i++) {
            originalTree[parent[i]].push_back(i);
        }
        dfs(0, parent, s);
        find(0);
        return ans;
    }
};