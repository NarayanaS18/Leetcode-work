class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                count++;
                ans = max(ans, count);
            }
            else if(nums[i] == 0){
                ans = max(ans, count);
                count = 0;
            }
        }
        return ans;
    }
};