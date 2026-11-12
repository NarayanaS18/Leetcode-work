class Solution {
public:
    int f(vector<vector<int>>& mat, int col){
        int m = mat.size(), maxi = INT_MIN;
        int idx = 0;
        for(int i=0; i<m; i++){
            if(mat[i][col] > maxi){
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int st = 0, end = n-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            int maxIdx = f(mat, mid);
            int left = (mid > 0) ? mat[maxIdx][mid-1] : -1;
            int right = (mid < n-1) ? mat[maxIdx][mid+1] : -1;
            if(mat[maxIdx][mid] > right && mat[maxIdx][mid] > left){
                return {maxIdx, mid};
            }
            else if(mat[maxIdx][mid] < left){
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return {-1, -1};
    }
};