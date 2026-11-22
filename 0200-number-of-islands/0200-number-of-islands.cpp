class Solution {
public:

    void f(int i, int j, vector<vector<char>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(i < 0 || j < 0 || i > m-1 || j > n-1 || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0'; //sink the  land
        f(i-1, j, grid);
        f(i, j+1, grid);
        f(i+1, j, grid);
        f(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    f(i, j, grid);
                }
            }
        }
        return cnt;
    }
};