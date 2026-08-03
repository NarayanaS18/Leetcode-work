class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> temp;
        for(int j=0; j<n; j++){
            vector<int> col(n, 0);
            for(int i=0; i<n; i++){
                col[i] = matrix[i][j];
            }
            reverse(col.begin(), col.end());
            temp.push_back(col);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = temp[i][j];
            }
        }
    }
};