class Solution {
public:

    bool binarySearch(vector<vector<int>>& matrix, int row, int tar){
        int n = matrix[0].size();
        int st = 0, end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(matrix[row][mid] == tar) return true;
            if(matrix[row][mid] < tar) st = mid+1;
            else end = mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0, er = m-1;
        while(sr <= er){
            int mr = sr + (er - sr)/2;

            if(matrix[mr][0] <= target && matrix[mr][n-1] >= target){
                if(binarySearch(matrix, mr, target)){
                    return true;
                }
            }
            if(matrix[mr][n-1] < target){
                sr = mr+1;
            }
            else{
                er = mr-1;
            }
        }
        return false;
    }
};