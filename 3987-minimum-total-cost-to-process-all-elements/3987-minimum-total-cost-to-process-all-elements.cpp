class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long mod = 1e9+7;
        int n = nums.size();
        if(n == 0) return 0;
        
        long long cost = 0;
        long long temp = k;
        long long ans = 0;
        for(int i=0; i<n; i++){
            if(temp < nums[i]){  
                long long need = (nums[i] - temp + k - 1ll)/k;
                __int128 sum_need  =  (__int128)need * cost + (__int128)need * (need + 1)/2; 
                ans = (ans + (long long)(sum_need % mod))%mod;

                cost += need;
                temp += need * 1ll * k;
            }
            temp = temp - nums[i];
        }
        return ans % mod;
    }
};