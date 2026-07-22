class Solution {
public:

    int f(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == 0) return nums[0];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notPick = 0 + f(idx-1, nums, dp);
        int pick = nums[idx] + f(idx-2, nums, dp);
        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev = nums[0], prev2 = 0;
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notPick = 0 + prev;
            int cur = max(pick, notPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};