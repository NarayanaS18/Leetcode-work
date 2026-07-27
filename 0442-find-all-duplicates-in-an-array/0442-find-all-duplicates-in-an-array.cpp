class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {};
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};