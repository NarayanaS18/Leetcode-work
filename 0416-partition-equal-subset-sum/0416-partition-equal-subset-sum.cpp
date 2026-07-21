class Solution {
public:

    bool isSubsetSum(vector<int>& nums, int k){
        int n = nums.size();
        vector<bool> prev(k+1, false), cur(k+1, false);
        prev[0] = cur[0] = true;
        if (nums[0] <= k) prev[nums[0]] = true;

        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                bool pick = false, notPick = false;
                notPick = prev[j];
                if(nums[i] <= j) pick = prev[j-nums[i]];
                cur[j] = pick || notPick;
            }
            prev = cur;
        }
        return prev[k];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;

        return isSubsetSum(nums, sum/2);
    }
};