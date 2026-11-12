class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int increase = 1, decrease = 1, maxlen = 1;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                increase++;
                decrease = 1;
            }

            else if(nums[i] < nums[i-1]){
                decrease++;
                increase = 1;
            }
            else{
                increase = 1;
                decrease = 1;
            }
            maxlen = max(maxlen, max(increase, decrease));
        }
        return maxlen;
    }
};