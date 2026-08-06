class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int mini = n/3 + 1;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;

            if(m[nums[i]] == mini) ans.push_back(nums[i]);

            if(ans.size() == 2) break;
        }
        sort(ans.begin(), ans.end());
        return ans;


    }
};