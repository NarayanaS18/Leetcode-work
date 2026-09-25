class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxlen = 1, cnt = 1;
        int lastsmall = INT_MIN;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastsmall){
                cnt++;
                lastsmall = nums[i];
            }
            else if(nums[i] != lastsmall){
                cnt = 1;
                lastsmall = nums[i];
            }
            maxlen = max(maxlen, cnt);
        }
        return maxlen;
    }
};