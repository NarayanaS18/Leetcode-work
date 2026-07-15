class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid){
        int n = grid.size(), m = grid[0].size();
        
        if(i < 0 || i >= n ||j < 0 || j >= m || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0'; //sink the island
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, grid);
                    
                }
            }
        }
        return ans;
    }
};