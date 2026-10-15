class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target) return true;
            
            if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++;
                end--;
                continue;
            }

            //check if left half is sorted
            if(nums[st] <= nums[mid]){
                if(nums[st] <= target && target < nums[mid]){
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }

            //check if right half is sort
            else{
                if(target > nums[mid] && target <= nums[end]){
                    st = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }

        return false;
    }
};