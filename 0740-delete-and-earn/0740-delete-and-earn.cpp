class Solution {
public:

    int f(int idx, vector<int>& points, vector<int>& dp){
        if(idx <= 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int notPick = f(idx-1, points, dp);
        int pick = points[idx] + f(idx-2, points, dp);
        return dp[idx] = max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxVal = INT_MIN;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, nums[i]);
        }
        vector<int> points(maxVal+1, 0);
        for(int val : nums){
            points[val] += val;
        }

        vector<int> dp(maxVal+1, 0);
        for(int i=1; i<points.size(); i++){
            int pick = points[i];
            if(i > 1){
                pick += dp[i-2];
            }
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[maxVal];
    }
};