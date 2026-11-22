class Solution {
public:

    void f(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i > m-1 || j > n-1 || grid[i][j] == '0' || vis[i][j] != -1){
            return;
        }
        vis[i][j] = 1;
        f(i-1, j, grid, vis);
        f(i, j+1, grid, vis);
        f(i+1, j, grid, vis);
        f(i, j-1, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] != -1) continue;
                if(grid[i][j] == '1'){
                    f(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};