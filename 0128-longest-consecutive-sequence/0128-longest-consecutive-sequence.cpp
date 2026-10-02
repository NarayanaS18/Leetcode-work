class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxlen = 1, cnt = 1;
        int lastSmall = INT_MIN;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmall){
                cnt++;
                lastSmall = nums[i];
            }
            else if(nums[i] != lastSmall){
                cnt = 1;
                lastSmall = nums[i];
            }
            maxlen = max(maxlen, cnt);
        }
        return maxlen;
    }
};