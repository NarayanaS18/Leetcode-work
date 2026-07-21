class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;
        if(n == 1) return true;

        int st = 0, end = n-1;
        int mid = st + (end-st)/2;
        while(st < end){
            if(nums[st] == nums[mid] || nums[mid] == nums[end]){
                return false;
                break;
            }
            st++;
            end--;
        }

        return true;
    }
};