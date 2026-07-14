class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int o){
        //check up
        if(sr > 0 && image[sr-1][sc] == o){
            image[sr-1][sc] = color;
            dfs(image, sr-1, sc, color, o);
        }
        //check right
        if(sc < image[0].size()-1 && image[sr][sc+1] == o){
            image[sr][sc+1] = color;
            dfs(image, sr, sc+1, color, o);
        }
        //check down
        if(sr < image.size()-1 && image[sr+1][sc] == o){
            image[sr+1][sc] = color;
            dfs(image, sr+1, sc, color, o);
        }
        //check left
        if(sc > 0 && image[sr][sc-1] == o){
            image[sr][sc-1] = color;
            dfs(image, sr, sc-1, color, o);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int o = image[sr][sc];
        if(color == o) return image;
        image[sr][sc] = color;
        dfs(image, sr, sc, color, o);
        return image;
    }
};