class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> temp;
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j=i; j<n; j++){
                if(nums[i] == nums[j]) cnt++;
            }
            if(cnt > n/3) temp.insert(nums[i]); 
        }
        vector<int> ans(temp.begin(), temp.end());
        return ans;

        
    }
};