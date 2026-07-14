class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0'; //sink the island to prevent revisiting
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int noOfIsland = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    noOfIsland++;
                    dfs(i, j, grid);
                }
            }
        }
        return noOfIsland;
    }
};