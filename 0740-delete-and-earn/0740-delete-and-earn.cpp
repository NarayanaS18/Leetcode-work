class Solution {
public:

    int f(int idx, vector<int>& points, vector<int>& dp){
        if(idx <= 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int pick = points[idx] + f(idx-2, points, dp);
        int notPick = f(idx-1, points, dp);

        return dp[idx] = max(pick, notPick);
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxVal = INT_MIN;
        for(int i=0; i<n; i++){
            maxVal = max(maxVal, nums[i]);
        }
        vector<int> points(maxVal+1, 0);
        for(int i=0; i<n; i++){
            points[nums[i]] += nums[i];
        }

        int prev2 = 0, prev = 0;
        for(int i=1; i<maxVal+1; i++){
            int pick = points[i];
            if(i > 1) pick += prev2;
            int notPick = prev;
            int cur = max(pick, notPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};