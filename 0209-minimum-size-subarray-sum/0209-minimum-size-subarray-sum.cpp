class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minlen = 1e9;
        int i = 0, j = 0, sum = 0;
        while(j < n){
            sum += nums[j];

            while(sum >= target){
                if(j-i+1 < minlen){
                    minlen = j-i+1;
                }
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minlen >= 1e9) return 0;
        return minlen;
    }
};