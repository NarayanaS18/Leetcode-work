class Solution {
public:

    int f(int curr, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(curr == nums.size()) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int pick = 0, notPick = 0;
        notPick = 0 + f(curr+1, curr, nums, dp);
        if(prev == -1 || nums[prev] < nums[curr]){
            pick = 1 + f(curr+1, curr, nums, dp);
        }
        return dp[curr][prev+1] = max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};