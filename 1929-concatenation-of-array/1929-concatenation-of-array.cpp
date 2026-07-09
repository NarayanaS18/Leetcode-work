class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans = nums;

        for(int i=n; i<2*n; i++){
            ans.push_back(nums[i%n]);
        }

        return ans;
    }
};