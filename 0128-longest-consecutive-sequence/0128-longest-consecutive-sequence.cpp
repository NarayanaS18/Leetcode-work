class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0, lastSmall = INT_MIN;
        int len = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmall){
                len++;
                lastSmall = nums[i];
            } 
            else if(nums[i] != lastSmall){
                len = 1;
                lastSmall = nums[i];
            }
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};