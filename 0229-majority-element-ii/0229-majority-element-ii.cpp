class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> temp;
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/3){ 
                temp.insert(nums[i]);
            }
        }
        vector<int> ans(temp.begin(), temp.end());
        return ans;
    }
};