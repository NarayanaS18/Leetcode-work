class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        
        // vis tracking: 0 = unvisited, 2 = visited/rotten
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int freshOrange = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Crucial: Mark initial rotten oranges as visited!
                }
                if(grid[i][j] == 1){
                    freshOrange++;
                }
            }
        }
        
        int time = 0, count = 0;
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    count++;
                }
            }
        }
        
        if(count != freshOrange) return -1;
        return time;
    }
};