class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), minlen = 1e9;
        int i = 0, j = 0, sum = 0;
        while(j < n){
            sum += nums[j];

            while(sum >= target){
                int len = j-i+1;
                minlen = min(len, minlen);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return (minlen >= 1e9) ? 0 : minlen;
    }
};