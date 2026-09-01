class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int sr = -1, sc = -1;
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                } else if (classroom[i][j] == 'L') {
                    dp[i][j] = count++;
                }
            }
        }
        if (count == 0) {
            return 0;
        }
        int targetMask = (1 << count) - 1;
        queue<tuple<int, int, int, int,int>> q;
        q.push({sr, sc, energy, 0, 0});
        vector<vector<vector<vector<bool>>>> visited(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy + 1, vector<bool>(1 << count, false))));
        visited[sr][sc][energy][0] = true;
        int dir[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            auto [r, c, e, mask, steps] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    classroom[nr][nc] != 'X') {
                    int nxt_e = e - 1;
                    int nxt_mask = mask;
                    if (classroom[nr][nc] == 'L') {
                        nxt_mask |= (1 << dp[nr][nc]);
                    }

                    if (nxt_mask == targetMask) {
                        return steps + 1;
                    }

                    if (classroom[nr][nc] == 'R') {
                        nxt_e = energy;
                    }
                    if (nxt_e == 0 && classroom[nr][nc] != 'R') {
                        continue;
                    }
                    if (!visited[nr][nc][nxt_e][nxt_mask]) {
                        visited[nr][nc][nxt_e][nxt_mask] = true;
                        q.push({nr, nc, nxt_e, nxt_mask, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};