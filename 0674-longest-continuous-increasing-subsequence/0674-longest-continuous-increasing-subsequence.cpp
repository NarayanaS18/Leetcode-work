class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int len = 1, maxlen = 1;
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                len++;
                maxlen = max(maxlen, len);
            }
            else{
                len = 1;
            }
        }
        return maxlen;
    }
};