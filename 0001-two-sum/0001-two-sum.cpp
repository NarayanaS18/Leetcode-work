class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int second = target - nums[i];
            if(mp.find(second) != mp.end()){
                return {i, mp[second]};
            }
            else if(mp.find(second) == mp.end()){
                mp[nums[i]] = i;
            }
        }
        return {-1,-1};
    }
};