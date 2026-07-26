class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int st = -1, end = -2;
        int maxi = nums[0], mini = nums[n-1];

        for(int i=1; i<n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[n-1-i]);

            if(nums[i] < maxi){
                end = i;
            }
            if(nums[n-1-i] > mini){
                st = n-1-i;
            }
        }
        return end-st+1;
    }
};