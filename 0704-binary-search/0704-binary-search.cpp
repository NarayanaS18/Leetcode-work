class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n = nums.size();
        int st = 0, end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == tar) return mid;
            else if(nums[mid] < tar) st = mid+1;
            else end = mid-1;
        }
        return -1;
    }
};