class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& vis){
        if(i < 0 || j < 0 || i >= vis.size() || j >= vis[0].size() || vis[i][j] == '0'){
            return;
        }
        vis[i][j] = '0';//sink the island;
        dfs(i-1, j, vis);
        dfs(i+1, j, vis);
        dfs(i, j-1, vis);
        dfs(i, j+1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> vis = grid;
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == '1'){
                    dfs(i, j, vis);
                    count++;
                }
            }
        }
        return count;
    }
};