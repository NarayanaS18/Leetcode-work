class Solution {
public:

    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m = grid.size(), n = grid[0].size();
    
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || vis[i][j] == 1){
            return 0;
        }
        vis[i][j] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int currArea = 1;
        for(int k=0; k<4; k++){
            int nrow = i + drow[k];
            int ncol = j + dcol[k];
            currArea += f(nrow, ncol, grid, vis);
        }
        return currArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int maxArea = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    maxArea = max(f(i, j, grid, vis), maxArea);
                }
            }
        }
        return maxArea;
    }
};