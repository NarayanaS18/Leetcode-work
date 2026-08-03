class Solution {
public:

    bool binarySearch(vector<vector<int>>& matrix, int row, int tar){
        int n = matrix[row].size();
        int st = 0, end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(matrix[row][mid] == tar){
                return true;
            }
            if(matrix[row][mid] < tar) st = mid+1;
            else end = mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        bool ans = false;
        int sRow = 0, eRow = m-1;
        while(sRow <= eRow){
            int midRow = sRow + (eRow - sRow)/2;
            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                ans = binarySearch(matrix, midRow, target);
                break;
            }
            else if(target >= matrix[midRow][n-1]){
                sRow = midRow+1;
            }
            else{
                eRow = midRow-1;
            }
        }
        return ans;
    }
};