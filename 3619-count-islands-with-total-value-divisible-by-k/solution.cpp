class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        auto dfs = [&](auto&& self, int i, int j) -> long long {
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
                return 0;
            }
            long long sum = grid[i][j];
            grid[i][j]=0;
            sum += self(self, i + 1, j);
            sum += self(self, i - 1, j);
            sum += self(self, i, j + 1);
            sum += self(self, i, j - 1);
            return sum;
        } ;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 0) {
                    long long s = dfs(dfs, i, j);
                    if (s % k == 0) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};