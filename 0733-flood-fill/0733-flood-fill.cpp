class Solution {
public:

    void f(vector<vector<int>>& image, int sr, int sc, int color, int o){
        int n = image.size(), m = image[0].size();
        //check up
        if(sr > 0 && image[sr-1][sc] == o){
            image[sr-1][sc] = color;
            f(image, sr-1, sc, color, o);
        }
        //check down
        if(sr < n-1 && image[sr+1][sc] == o){
            image[sr+1][sc] = color;
            f(image, sr+1, sc, color, o);
        }
        //check right
        if(sc < m-1 && image[sr][sc+1] == o){
            image[sr][sc+1] = color;
            f(image, sr, sc+1, color, o);
        }
        //check left
        if(sc > 0 && image[sr][sc-1] == o){
            image[sr][sc-1] = color;
            f(image, sr, sc-1, color, o);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int o = image[sr][sc];
        if(o == color) return image;
        image[sr][sc] = color;
        f(image, sr, sc, color, o);
        return image;
    }
};