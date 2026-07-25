class Solution {
public:

    int binarySearch(vector<int>& nums, int tar){
        int n = nums.size();
        int st = 0, end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == tar) return mid;
            if(nums[mid] < tar) st = mid+1;
            else end = mid-1;
        }
        return st;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int val : nums){
            if(ans.empty() || ans.back() < val){
                ans.push_back(val);
            }
            else{
                int idx = binarySearch(ans, val);
                ans[idx] = val;
            }
        }
        return ans.size();
    }
};