class Solution {
public:

    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,1,0,-1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n 
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = '1';
                    q.push({nrow, ncol});
                }
            }                    
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for(int row=0; row<m; row++){
            for(int col=0; col<n; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    bfs(row, col, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};