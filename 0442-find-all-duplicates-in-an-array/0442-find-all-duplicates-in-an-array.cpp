class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return {};
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(m.find(nums[i]) != m.end()){
                ans.push_back(nums[i]);
            }
            else if(m.find(nums[i]) == m.end()){
                m[nums[i]] = i;
            }
        }
        return ans;
    }
};