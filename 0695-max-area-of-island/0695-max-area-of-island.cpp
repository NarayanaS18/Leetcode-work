class Solution {
public:

    int dfs(vector<vector<int>>& vis, int i, int j, int m, int n){    
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] == 0){
            return 0;
        }

        vis[i][j] = 0;
        return 1 + dfs(vis, i-1, j, m, n) 
        + dfs(vis, i+1, j, m, n) 
        + dfs(vis, i, j-1, m, n) 
        + dfs(vis, i, j+1, m, n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis = grid;
        int maxArea = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == 1){              
                    maxArea = max(maxArea, dfs(vis, i, j, m, n));
                }
            }
        }
        return maxArea;
    }
};