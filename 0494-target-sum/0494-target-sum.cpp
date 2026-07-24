class Solution {
public:

    int f(int idx, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(idx == 0){
            if(arr[idx] == 0 && target == 0) return 2;
            if(arr[idx] == target || target == 0) return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int pick = 0, notPick = 0;
        notPick = f(idx-1, target, arr, dp);
        if(arr[idx] <= target) pick = f(idx-1, target-arr[idx], arr, dp);
        
        return dp[idx][target] = pick + notPick;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int> prev(target+1, 0), cur(target+1, 0);
        if(arr[0] == 0) prev[0] = 2;
        else{
            prev[0] = 1;
            if(arr[0] <= target) prev[arr[0]] = 1;
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<=target; j++){
                int pick = 0, notPick = 0;
                notPick = prev[j];
                if(arr[i] <= j) pick = prev[j-arr[i]];
                cur[j] = pick + notPick;
            }
            prev = cur;
        }
        return prev[target];
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size(), totSum = 0;
        for(int val : arr){
            totSum += val;
        }
        if((totSum - diff) % 2 || totSum - diff < 0) return 0;
        return perfectSum(arr, (totSum-diff)/2);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(nums, target);
    }
};