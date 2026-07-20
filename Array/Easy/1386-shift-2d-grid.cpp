// ═══════════════════════════════════════════════════════
// Problem: 1386. Shift 2D Grid
// Difficulty: Easy
// Topics: Array, Matrix, Simulation
// Runtime: 5 ms (Beats 23.7%)
// Memory: 18.1 MB (Beats 91.8%)
// Submitted: Jul 20, 2026
// Link: https://leetcode.com/problems/shift-2d-grid/
// ═══════════════════════════════════════════════════════

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int total = m * n;
        k = k % total;
        vector<vector<int>> result(n, vector<int>(m));
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
              int new_1d = (i * m + j + k) % total;
              int new_r = new_1d / m;
                int new_c = new_1d % m;
                result[new_r][new_c] = grid[i][j];
           }
        }
        return result;
    }
};
