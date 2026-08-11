class Solution {
public:

    // bool linearSearch(vector<int>& nums, int tar){
    //     int n = nums.size();
    //     for(int i=0; i<n; i++){
    //         if(nums[i] == tar) return true;
    //     }
    //     return false;
    // }

    int longestConsecutive(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        sort(nums.begin(), nums.end());
        int longest = 1, cnt = 0, lastSmaller = INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]-1 == lastSmaller){
                cnt++;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(cnt, longest);
        }
        return longest;
    }
};