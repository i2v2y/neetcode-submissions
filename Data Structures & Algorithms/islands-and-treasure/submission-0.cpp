class Solution {
   public:
    int m, n;
    queue<pair<int, int>> q;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            bfs(grid, r + 1, c, grid[r][c]);
            bfs(grid, r - 1, c, grid[r][c]);
            bfs(grid, r, c + 1, grid[r][c]);
            bfs(grid, r, c - 1, grid[r][c]);
        }
    }

    void bfs(vector<vector<int>>& grid, int r, int c, int d) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX) return;
        grid[r][c] = d + 1;
        q.push({r, c});
    }
};
